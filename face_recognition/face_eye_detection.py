from cv2 import waitKey
import numpy as np
import cv2

cap = cv2.VideoCapture(0)
fcas = cv2.CascadeClassifier(cv2.data.haarcascades + 'haarcascade_frontalface_default.xml')
ecas = cv2.CascadeClassifier(cv2.data.haarcascades + 'haarcascade_eye.xml')

while True:
    ret,frame = cap.read()
    
    if ret == False:
        continue
    
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    faces = fcas.detectMultiScale(gray, 1.3, 5) 
    
    #drawing a rectangle around the face on the image
    for (x,y,w,h) in faces:
        cv2.rectangle( frame, (x,y), (x+w,y+h), (79,244,255), 2 )
        roi_gray = gray[y:y+w, x:x+w]
        roi_color = frame[y:y+h, x:x+w]
        eyes = ecas.detectMultiScale(roi_gray, 1.3, 5)
        
        #drawing the rectangles aroung the eye
        for (ex,ey,ew,eh) in eyes:
            cv2.rectangle( roi_color, (ex,ey), (ex+ew,ey+eh), (255,0,0), 2 )
        
    frame = cv2.flip(frame,1)
      
    cv2.imshow('frame', frame)
    
    if cv2.waitKey(1) == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()