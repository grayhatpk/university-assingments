import tkinter as tk
import os
import tkinter.filedialog as filedialog
import tkinter.simpledialog as simpledialog

mainWin = tk.Tk() #an instant for the tkinter 

def main():
    
    mainWin.title("File Explorer")
    
    mainWin.geometry("1350x735")
    mainWin.resizable(0,0)

    list =[]   
    frame_objs=[] 
    button=[]
    path_=" " 
    address=[]
    t_address=0
    size=0
    i=0
    
    r=0
    c=0
    numb=0
    source_file=''
    destination=''
    index=''
    labell=None
    
    clm=0
    rws=0
    
    def copy_file():
        nonlocal source_file # the variable is of the outer function don't again declare it in this function 
        source_file = index
        print(source_file)
        
    def pasting():
        nonlocal source_file
        source_file
        print(source_file)
              
        frame =tk.Frame(label1,bd=2,border=5,relief="groove",bg="green")
        frame.grid(row=5,column=1,padx=50 ,pady=30)
        frame.grid_propagate(True)

        button=tk.Button(frame,text="{}".format(source_file))
        button.grid(row=0,column=0,padx=0,pady=0)
        button.grid_propagate(True)
                    
    #def button_command(num):
     #   print("THe Button Pressed {}".format(num))                
                    
    def renaming(numb,col,row):
        nonlocal source_file
        nonlocal button
        nonlocal frame_objs
        nonlocal labell
        
        source_file=index
        print(list[numb])
       
        new_name=simpledialog.askstring("New Directory Name", "Enter the new directory Name:") 
        
        old_path = os.path.join(address[-1], list[numb])
        new_path = os.path.join(address[-1], new_name)
        os.rename(old_path, new_path)       
        
        button[numb].config(text=new_name)
    
    #def deleting():
        
        
        
           
        
    def show_menu(event,ind,label1,number,column,row):
       
        nonlocal index
        nonlocal i
        nonlocal labell
        labell=label1
        nonlocal numb
        numb=number
        
        nonlocal clm
        nonlocal rws
        
        clm=column
        rws=row
        
        m.post(event.x_root,event.y_root)
        index=ind
            
    m=tk.Menu(mainWin,tearoff=0)
    m.add_command(label="Copy",command=copy_file)
    m.add_command(label="Rename",command=lambda:renaming(numb,clm,rws))
    m.add_command(label="Paste",command=pasting)     
    m.add_separator()
    m.add_command(label="Delete")    
    
    def show_directories(path,flag):
        #r=0
        #c=0
        path_=path
        num=0
        nonlocal r
        nonlocal c
    
        nonlocal list
        nonlocal t_address  # the variable is declared outside of this function so nonlocal is used to tell this to inner function 
        nonlocal size       
        nonlocal button
        nonlocal frame_objs
        
        if(path!="This PC"):
            size=os.path.getsize(path)
        
        labellds.config(text="{} Bytes".format(size)) # showing the size of the files in bytes 
        
        t_address=t_address+1
        address.append(path)
        
        if(flag==1):
            #condition 
            if(len(address) !=0 ):
                path=address.pop()
                path_=path
                            
        elif(flag == 2 or len(address)==0):
               #show_directories("This PC")    
                print("directory empty")
                
        for widgets in label1.winfo_children(): # first clearing the frame 
            widgets.destroy()
        
        label00.config(text=path)
        
        if (path != "This PC"):
            list=os.listdir(path)
        
        frame_objs=[None] *len(list)
        button=[None] * len(list)
        
        for i in list:
            if num%4 != 0:
                frame_objs[num]=tk.Frame(label1,bd=2,border=5,relief="groove",bg="green")
 
                frame_objs[num].grid(row=r,column=c,padx=50 ,pady=30)
                frame_objs[num].grid_propagate(True)
            
                button[num]=tk.Button(frame_objs[num],text="{}".format(i))
                button[num].config(command=lambda dir=i:label1.config(text=show_directories(path_ +"\\" +dir,0)))
                button[num].bind("<Button-3>",lambda event ,pat=i ,cl=c ,rw=r,number=num: show_menu(event,pat,label1,number,cl,rw))
           
                button[num].grid(row=r,column=c,padx=0,pady=0)
                button[num].grid_propagate(True)
                
                c+=1
            elif num %4 ==0:
                r+=1
                c=0
                frame_objs[num]=tk.Frame(label1,bd=2,border=5,relief="groove",bg="green") 
                frame_objs[num].grid(row=r,column=c,padx=50,pady=30)
                
                button[num]=tk.Button(frame_objs[num],text="{}".format(i),command=lambda dir=i: label1.config(text=show_directories(path_ +"\\"+ dir,0)))
                button[num].bind("<Button-3>",lambda event ,pat=i , number=num: show_menu(event,pat,label1,number))
                button[num].grid(row=r,column=c,padx=0,pady=0)

                c+=1
                
            num=num+1
        #print(address)
        #print(t_address)
        
            
  # Within in the Main Function 
    
    backforth=tk.Frame(mainWin,bd=2,border=5,relief="groove",bg="yellow")
    backforth.pack(side="top",fill="x",padx=0,pady=0,expand=0)
    t_address-=1
         
    labelb=tk.Button(backforth,relief="solid",text=" < --- ",command=lambda:label1.config(text=show_directories(address.pop(),1) if len(address)!=0 else None ))
    labelb.grid(row=0,column=0,padx=30,pady=5,sticky="ew")
    #labelb.pack()
    
    forth=tk.Frame(backforth,bd=0,border=0,relief="groove")
    forth.grid(row=0,column=1,padx=1,pady=5)
    
    labelf=tk.Button(forth,relief="solid",text=" --- > ")
    labelf.grid(row=0,column=0,padx=0,pady=0,sticky="ew")
    #labelf.pack()
    
    
    downframe=tk.Frame(mainWin,bd=2,border=5,relief="groove",bg="grey")
    downframe.pack(side="bottom",fill="x",padx=0,pady=0,expand=0)
    
    labeld=tk.Label(downframe,text="File Size ---> ")#,bg="grey")
    labeld.grid(row=0,column=1,padx=10,pady=0)
    
    labellds=tk.Label(downframe,text=" "*15)
    labellds.grid(row=0,column=3,padx=30,pady=0)
    
    frame0=tk.Frame(mainWin,bd=2,border=5,relief="groove",bg="brown")
    frame0.pack(side="top",fill="both",padx=0,pady=0,expand=0)
    
    label0=tk.Label(frame0,text="path -> ")#,width=,height=,wraplength=)
    label0.grid(row=0,column=0,padx=10,pady=5)
    
    label00=tk.Label(frame0,text="\t\t\t",bg="green")
    label00.grid(row=0,column=1,padx=15,pady=5)
    
    frame_obj1=tk.Frame(mainWin,bd=2,border=5,relief="groove")
    frame_obj1.pack_propagate(0)
    frame_obj1.pack(side="right",fill="both",padx=0,pady=0,expand=1)

    label1=tk.Label(frame_obj1,width=166,height=48,wraplength=400)
    label1.grid(row=0,column=1,padx=0,pady=0)
    
    labeltext=tk.Label(label1,relief="solid",text=" Devices and Drives------------------------------------------------------------------ ",bg="sky blue")
    labeltext.grid(row=0,column=0,padx=50,pady=60)
    labeltext.grid_propagate(False)
    
    labeldirc=tk.Button(label1,relief="solid",text="Local Disk (C:) ",bg="sky blue",command=lambda:label1.config(text=show_directories("C:\\",0)))
    labeldirc.grid(row=1,column=0,padx=70,pady=0)
    
    labeldird=tk.Button(label1,relief="solid",text="Local Disk (D:) ",bg="sky blue",command=lambda:label1.config(text=show_directories("D:\\",0)))
    labeldird.grid(row=1,column=2,padx=50,pady=0)
    
    labeldirf=tk.Button(label1,relief="solid",text="Local Disk (F:) ",bg="sky blue",command=lambda:label1.config(text=show_directories("F:\\",0)))
    labeldirf.grid(row=1,column=4,padx=70,pady=0)
    
    left_wind=tk.Frame(mainWin,bd=2,border=5,relief="groove",bg="white")
    #left_wind.pack_propagate(0)
    left_wind.pack(side="left",fill="both") 
    
    desktop_frame=tk.Frame(left_wind,bg="white",border=0)
    desktop_frame.grid(row=0,column=0,padx=40,pady=40)
    
    label2=tk.Button(desktop_frame,relief="solid",text=" >  Desktop ",command=lambda:label1.config(text=show_directories("C:\\Users\\HP\\OneDrive\\Desktop",0)))
    label2.grid(row=0,column=0,padx=0,pady=0)
    #label2.grid_propagate(False)
    
    download_frame=tk.Frame(left_wind,bg="white",border=0)
    download_frame.grid(row=1,column=0,padx=20,pady=20)
    
    label3=tk.Button(download_frame,relief="solid",text=" >  Downloads ",command=lambda:label1.config(text=show_directories("C:\\Users\\HP\\Downloads",0)))
    label3.grid(row=1,column=0,padx=0,pady=0)
    #label2.grid_propagate(False)
    
    document_frame=tk.Frame(left_wind,bg="white",border=0)
    document_frame.grid(row=2,column=0,padx=20,pady=20)
    
    label4=tk.Button(document_frame,relief="solid",text=" > Documents ",command=lambda:label1.config(text=show_directories("C:\\Users\\HP\\OneDrive\\Documents",0)))
    label4.grid(row=2,column=0,padx=0,pady=0)
    #label2.grid_propagate(False)
    
    picture_frame=tk.Frame(left_wind,bg="white",border=0)
    picture_frame.grid(row=3,column=0,padx=20,pady=20)
    
    label5=tk.Button(picture_frame,relief="solid",text=" > Pictures ")
    label5.config(command=lambda:label1.config(text=show_directories("C:\\Users\\HP\\Desktop\\Pictures",0)))
    label5.grid(row=3,column=0,padx=0,pady=0)
    
    videos_frame=tk.Frame(left_wind,bg="white",border=0)
    videos_frame.grid(row=4,column=0,padx=20,pady=20)
    
    label6=tk.Button(videos_frame,relief="solid",text=" > Videos ")
    label6.config(command=lambda:label1.config(text=show_directories("C:\\Users\\HP\\Videos",0)))
    label6.grid(row=4,column=0,padx=0,pady=0)
    
    pc_frame=tk.Frame(left_wind,bg="white",border=0)
    pc_frame.grid(row=5,column=0,padx=20,pady=20)
    
    label7=tk.Button(pc_frame,relief="solid",text=" > This PC ",command=lambda:label1.config(text=show_directories("This PC",2)))
    label7.grid(row=4,column=0,padx=0,pady=0)
    
    mainWin.mainloop() 
       
main()

