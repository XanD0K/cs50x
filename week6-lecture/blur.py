# That's pset4 "Filter" - 'blur', in Python

# Library from Python (PIL = Python Image Library)
# In Python, they are called 'modules' and 'packages'
from PIL import Image, ImageFilter

before = Image.open("brigde.bmp")
after = before.filter(ImageFilter.BoxBlur(1))
after.save("out.bmp")

# for the 'edge' code, is the following
"""
before = Image.open("brigde.bmp")
after = before.filter(ImageFilter.FIND_EDGES(1))
after.save("out.bmp")
"""
