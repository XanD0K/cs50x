# 'pip install qrcode'

import os #access to file system, to read and write
import qrcode

img = qrcode.make("http://youtu.be/xvFZjo5PgG0")

img.save("qr.png", "PNG")
