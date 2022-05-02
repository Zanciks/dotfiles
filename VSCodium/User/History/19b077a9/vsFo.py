from tkinter import * 
from PIL import Image,ImageTk

root = Tk()

def exitProgram():
    exit()

def Talk():
    exit()

buddyMenu = Menu(root, tearoff = False)
buddyMenu.add_command(label = "Talk")
buddyMenu.add_command(label = "Exit", command = exitProgram)

def popupMenu(event):
    buddyMenu.tk_popup(event.x_root, event.y_root)

root.bind("<Button-3>", popupMenu)

canvas = Canvas(root, width = 144, height = 468)
canvas.pack()
canvas.create_image(144, 468, anchor = CENTER, image = ImageTk.PhotoImage(Image.open("output-onlinepngtools.png")))

root.geometry("144x468")
root.wait_visibility(root)
root.wm_attributes('-alpha', 1)
root.mainloop()