from tkinter import * 

root = Tk()

background_image = PhotoImage(file = "output-onlinepngtools.png")

label1 = Label(root, image = background_image)
label1.place(x = 0, y = 0)

root.mainloop()