import qrcode
import image
import tkinter as tk
from PIL import Image       
import os                                                                         


standardFont=("Comic Sans",18)
packargs={
    "padx":20,
    "pady":20
}
root =tk.Tk()
root.geometry("500x500")
root.title("MAN07HAR")

label=tk.Label(
    root,
    text="QR Code Generator",
    font=standardFont
)
label.pack(**packargs)

textArea=tk.Text(
    root,
    height=3,
    font=standardFont
)
photo=tk.PhotoImage(file="")
myLabel=tk.Label(image=photo)

textArea.pack(**packargs)
def generateQrCode():
    inp=textArea.get(
        "1.0",
        "end-1c"
    )
    qr=qrcode.QRCode(
    version =1,
    box_size=10,
    border=5
    )
    qr.add_data(inp)
    qr.make(fit=True)
    img=qr.make_image(fill="black",back_color="white")
    img.save(f"{inp}test.png")
    img = Image.open(f"{inp}test.png")
    
    photo.config(
        file=f"{inp}test.png"
    )



button1=tk.Button(
    root,
    text="Get My QR",
    font=standardFont,
    command=generateQrCode
)

button1.pack(**packargs)
myLabel.pack(**packargs)
root.mainloop()