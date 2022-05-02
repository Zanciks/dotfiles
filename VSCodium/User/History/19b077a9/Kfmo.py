from tkinter import * 
from PIL import Image,ImageTk
import os 

root = Tk()
# root.overrideredirect(True)
root.wm_attributes("-topmost", True)
# root.wm_attributes("-type", "splash")

def exitProgram():
    exit()
def talk():
    exit()

buddyMenu = Menu(root, tearoff = False)
buddyMenu.add_command(label = "Talk", command = talk)
buddyMenu.add_command(label = "Exit", command = exitProgram)

def popupMenu(event):
    buddyMenu.tk_popup(event.x_root, event.y_root)
root.bind("<Button-3>", popupMenu)

photoimage = ImageTk.PhotoImage(file = "ZeroTwoStanding.png")
width, height = photoimage.width(), photoimage.height()
canvas = Canvas(root, width = width, height = height)
canvas.pack()

canvas.create_image(0, 0, image=photoimage, anchor=NW)

root.mainloop()