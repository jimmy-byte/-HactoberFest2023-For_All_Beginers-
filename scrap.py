from bs4 import BeautifulSoup
import requests

url = input("Enter the url you want to scrap  :")


response = requests.get(url)

# to get the source code of the page 
data = response.text

# to get it clear
soup = BeautifulSoup(data,'html.parser')

print(soup)
 
#to find all the links on webpage
tags = soup.find_all("a")

#to find all the links with class name "result-title" on webpage
titles = soup.find_all("a",{"class":"result-title"})


print("-------------------------All the links ------------------------")
# cleaning and finding  links 
for tag in tags:
	print(tag.get('href'))


print("--------------------------All the link with the class name result-title------------------------------")
#Finding all titles 
for title in titles:
	print(title.text)


jobs = soup.find_all("p",{"class":"result-info"})

for job in jobs:
	title = job.find("a",{"class":"result-title"}).text
	location_tag = job.find("span",{"class":"result-hood"})
	location = location_tag.text[2:-1] if location_tag else "N/A"
	date = job.find("time",{"class":"result-date"}).text
	link = job.find("a",{"class":"result-title"}).get('href')
	print('job title :',title,'\n Location  :',location,'\n DATE :',date,'\n Links  :',link)