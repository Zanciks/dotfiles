from tkinter import * 
from PIL import Image,ImageTk

root = Tk()
root.overrideredirect(True)
root.wm_attributes("-topmost", True)
root.wm_attributes("-transparent", True)
root.config(bg = "systemTransparent")

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

root.image = tk.PhotoImage(file = "output-onlinepngtools.png")
label = tk.Label(root, image=root.image)
label.config(bg = "systemTransparent")
label.pack()

root.mainloop()