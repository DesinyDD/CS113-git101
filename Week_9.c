#การสร้าง/แยก Branch

- คำสั่งสำหรับการสร้าง Branch 
	    $ git branch <branch-name>
    เช่น สร้าง Branch ชื่อ feature ด้วยคำสั่งนี้
	    $ git branch feature
    การสร้าง Branch ที่แยกออกจาก Branch เดิม (Branch หลักของ repository คือ master) เป็นการแยกส่วนการพัฒนาออกจากกัน ไม่ให้ปนกัน เพื่อคงสภาพ Checkpoint ที่เป็นส่วนใหญ่

- ตรวจสอบว่ามี Branch ใดบ้าง ด้วยคำสั่ง
	    $ git branch
    จะเห็นว่ามี * อยู่นำหน้าชื่อ Branch ที่กำลังพัฒนาอยู่ในปัจจุบัน

- เปลี่ยน Branch ไปที่ feature ด้วยคำสั่ง
	    $ git checkout feature

- ตรวจสอบ Branch อีกรอบด้วยคำสั่ง
	    $ git branch
    สังเกตว่า * จะไปอยู่หน้า Branch feature


#การ Merge Branch แบบไม่มี Conflict

- เพิ่มไฟล์ feature1.txt ใน branch feature และเพิ่มไฟล์ master1.txt ใน branch master
	$ git checkout feature
    ….. เพิ่มไฟล์ feature1.txt
    $ git status         			(สังเกตบรรทัดแรก จะบอกว่าอยู่ branch ไหนอยู่)
    $ git add feature1.txt
    $ git commit -m "Add feature1.txt in branch feature"

    $ git checkout master     		(สังเกตว่าไฟล์ feature1.txt จะหายไป)
    ….. เพิ่มไฟล์ master1.txt
    $ git status
    $ git add master1.txt
    $ git commit -m "Add master1.txt in branch master"

- ใช้ git log adog ดู Checkpoint ทั้งหมด
	    $ git log --all --decorate --oneline --graph
    สังเกตว่าจะมี 2 branches คือ master และ feature และ orgin/master ยังอยู่ที่เก่า

- push master ขึ้น github  ใช้ git log adog ดู Checkpoint ทั้งหมด สังเกตสิ่งที่เปลี่ยนแปลง
	$ git checkout master
	$ git log --all --decorate --oneline --graph
	$ git push origin master
    $ git log --all --decorate --oneline --graph

- push feature ขึ้น github  ใช้ git log adog ดู Checkpoint ทั้งหมด สังเกตสิ่งที่เปลี่ยนแปลง
	$ git checkout feature
	$ git log --all --decorate --oneline --graph
	$ git push origin feature
 	$ git log --all --decorate --oneline --graph

- ลอง merge โดยให้ งานใน feature ไปรวมกันใน master
    เปลี่ยนไปที่ Branch ปลายทางก่อน (master)
	$ git checkout master
    รวม Branch (merge) feature ให้ไปอยู่ใน master
	$ git merge feature

- เมื่อไม่มี conflict จะทำให้ git สร้าง commit ของการ merge นั้นไปเลย ดังนั้น เราจะต้องใส่ commit message ด้วย vi ถ้าใช้ default merge commit message ให้กด ESC แล้วพิมพ์ :wq! แล้วกด Enter

- เมื่อ merge แล้ว จะเห็นว่ามีทั้งไฟล์ master1.txt และ feature1.txt อยู่ใน Branch master

- สังเกต git log adog จะเห็นเส้นของการรวม Branch
	$ git log --all --decorate --oneline --graph

- push master ขึ้น github จะถือว่าการ merge นั้น สมบูรณ์
	$ git push origin master


#การ Pull แบบไม่มี Conflict

- ให้ clone git repository มาไว้อีกเครื่องหนึ่ง หรือ directory ใหม่ เช่น git102
	$ cd ..
    $ git clone <git-url> git102
	$ cd git102

- เพิ่มไฟล์ new-1.txt ใน directory ใหม่ (git102) แล้ว push ไปที่ github
    $ git add new-1.txt
    $ git commit -m "add new-1.txt by user2"
    $ git push origin master

- กลับมาที่เครื่องเก่า หรือ directory เก่า แล้ว pull การเปลี่ยนแปลงลงมาที่ local repository
	$ cd ..
	$ cd git101
	$ ls -l						(ไม่มีไฟล์ new-1.txt)
	$ git pull origin master	(ดึงการเปลี่ยนแปลงจาก branch master)
	$ ls -l						(มีไฟล์ new-1.txt)


#การ Merge แบบมี Conflict
	Conflict หรือความขัดแย้ง เกิดจากการปรับแก้ไขข้อมูลในไฟล์เดิม บรรทัดเดิม ที่อยู่ต่าง Branch กัน 
    เมื่อ merge แล้ว git ตัดสินใจไม่ได้ว่าจะใช้ข้อมูลจาก branch ใด

- สร้าง Branch feature2 และสลับไป Branch นั้นเลย ด้วยคำสั่ง
	$ git checkout -b feature2

- ให้แก้ไฟล์ b.txt ใน branch feature2 และ master ในบรรทัดเดียวกัน ให้มีข้อความต่างกัน
	$ git checkout feature2
	… แก้ไขไฟล์ b.txt บรรทัดแรก ให้มีข้อความหนึ่ง
	$ git status
	$ git add b.txt
	$ git commit -m "update b.txt first line in branch feature2"
	$ git log --all --decorate --oneline --graph

	$ git checkout master
	… แก้ไขไฟล์ b.txt บรรทัดแรก ให้มีข้อความสองที่แตกต่างจากข้อความหนึ่ง
	$ git status
	$ git add b.txt
	$ git commit -m "update b.txt first line in branch master"
	$ git log --all --decorate --oneline --graph

- merge branch feature2 เข้าไปใน branch master (ไม่ต้อง push ก็ merge ได้)
	    $ git checkout master
	    $ git merge feature2
    สังเกตว่า merge ไม่สำเร็จ มีข้อความว่าเกิด conflict ขึ้น

- เปิดไฟล์ b.txt ใน master จะเห็นว่า git สร้างข้อความที่อธิบาย conflict
    หาก Editor มี tool ที่ช่วยจัดการ conflict เช่น Atom สามารถเลือกว่าจะใช้ข้อมูลจาก branch ใด
    หาก Editor ไม่มี tool ช่วย เช่น sublime ต้อง เพิ่ม/แก้/ลบ เอง

- หลังจากแก้ไข conflict เสร็จแล้ว ให้ commit การ merge นั้น
	$ git add b.txt
	$ git status
	$ git commit -m "merge branch 'feature2' and resolve conflict"
	$ git log --all --decorate --oneline --graph

- push ขึ้น github
	    $ git push origin master
        $ git log --all --decorate --oneline --graph
    สังเกตว่า ไม่จำเป็นต้อง push feature2 เพราะถูก merge ไปกับ master แล้ว


#การ Pull แบบมี Conflict

- ในเครื่องใหม่ หรือ directory ใหม่ ให้แก้ไขข้อมูลใน new-1.txt แล้ว commit และ push ไปที่ github
	$ cd ..
	$ cd git102
	$ git pull origin master
	…  แก้ไขไฟล์ new-1.txt ใน git102
	$ git status
	$ git add new-1.txt
	$ git status
	$ git commit -m "update new-1.txt by user2"
	$ git log --all --decorate --oneline --graph
	$ git push origin master
    $ git log --all --decorate --oneline --graph

- ในเครื่องเก่า หรือ directory เก่า ให้แก้ไขข้อมูลใน new-1.txt บรรทัดเดียวกับข้อ 24 แล้ว commit
	$ cd ..
	$ cd git101
	…  แก้ไขไฟล์ new-1.txt บรรทัดเดียวกับข้อ 23 ให้มีข้อความใหม่
	$ git status
	$ git add new-1.txt
	$ git status
	$ git commit -m "update new-1.txt too"
	$ git log --all --decorate --oneline --graph

- ก่อน Push ให้ Pull origin/master จะพบว่าการ Pull นี้ มี conflict เกิดขึ้น
    ให้แก้ไข conflict ในไฟล์ new-1.txt จากนั้นสร้าง commit แล้ว push ไปที่ github
	    $ git pull origin master
        $ git status
        … แก้ไข conflict ในไฟล์ new-1.txt
        $ git add new-1.txt
        $ git status
        $ git commit -m "merge and resolve conflict in new-1.txt"
        $ git log --all --decorate --oneline --graph
        $ git push origin master
        $ git log --all --decorate --oneline --graph

- ที่เครื่องใหม่ หรือ directory ใหม่ จะเห็นว่า Checkpoint ตามหลัง origin/master อยู่
	    $ cd ..
	    $ cd git102
	    $ git log --all --decorate --oneline --graph
    ให้ pull ลงมา สังเกตว่า ไม่เกิด conflict เพราะไม่มีการแก้ไขอะไรเพิ่มเติม
	    $ git pull origin master
            $ git log --all --decorate --oneline --graph
