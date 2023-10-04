import pyqrcode
import png
from pyqrcode import QRCode
link = "https://www.youtube.com/"

url = pyqrcode.create(link)
url.png('myqr.png', scale = 15)
