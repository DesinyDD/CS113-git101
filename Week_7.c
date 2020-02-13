CS113-Git-1 พื้นฐานการใช้งาน Git ตอนที่ 1

ความรู้พื้นฐานการใช้คำสั่งบน Command Prompt (Windows) / Terminal (Mac) / Bash (Linux)
การใช้งาน
คำสั่งบน Command Prompt
คำสั่งบน Terminal/Bash
สร้าง directory ชื่อ myapp
mkdir myapp
mkdir myapp
ดูรายการ directories และ files
ใน working directory ปัจจุบัน
dir
ls
ดูรายการ directories และ files
ใน working directory ปัจจุบัน
แบบละเอียด
dir
ls -l
เปลี่ยนเป็น Drive D:
d:
(Mac ไม่มี Drive D:)
เปลี่ยน working directory เป็น directory lab01 ซึ่งอยู่ใน working directory
cd lab01
cd lab01
เปลี่ยน working directory เป็น directory ที่บรรจุ working directory
cd ..
cd ..
เปลี่ยน working directory เป็น root directory 
cd /
cd /

การใช้งาน Git ตอนที่ 1

1. การติดตั้ง Git ในเครื่องคอมพิวเตอร์ ให้ดาวน์โหลดโปรแกรมจาก https://git-scm.com/downloads
   เลือกให้ตรงกับระบบปฏิบัติการของเครื่องตนเอง แล้วติดตั้งในเครื่องของตนเอง
   (เครื่องในห้องแลป ติดตั้ง Git ไว้แล้ว)

2. ตรวจสอบว่า Git ใช้งานได้ โดยเปิด Command Prompt / Terminal แล้วพิมพ์คำสั่ง
	git --version
    จะปรากฏผลลัพธ์เป็น Version ของ Git ที่ลงในเครื่อง (ปัจจุบันคือ 2.25.0 on Windows, 2.23.0 on Mac)

ขั้นตอนที่ 1 และ 2 เป็นการติดตั้ง Git ซึ่งทำเพียงครั้งเดียว ยกเว้นต้องการลง version ใหม่ ให้กลับไปทำขั้นตอนที่ 1

3. สร้าง directory ที่จะเก็บงาน (สมมติชื่อ git101) แล้วเปลี่ยน working directory ไปที่ directory นั้น


4. Initialize git repository (git project) (ขั้นตอนนี้จะทำทุกครั้งที่มี git repository ใหม่)
	git init
     สังเกตว่ามี directory ชื่อ .git

5. สร้างไฟล์ a.txt ให้มีข้อความว่า Hello git

6. ตรวจสอบสถานะของไฟล์ ว่ามีไฟล์ใดเปลี่ยนแปลงใน git repository หรือไม่
	git status
     ควรตรวจสอบสถานะของไฟล์ทุกครั้ง เมื่อมีการสร้างไฟล์ใหม่ หรือไฟล์เดิมมีการแก้ไข หรือไฟล์ถูกลบ

7. เพิ่มไฟล์เข้า staging area เพื่อพร้อมจะ commit แล้วตรวจสอบสถานะอีกครั้งหนึ่ง
	git add a.txt
	git status

8. ตั้งค่าชื่อและอีเมลเพื่อระบุตัวผู้ commit
	git config user.name "Your Name"
	git config user.email "yourmail@ku.th"

    ถ้าเป็นเครื่องส่วนตัว ให้ใส่ option --global (global) ด้วย
	git config --global user.name "Your Name"
	git config --global user.email "yourmail@ku.th"

    ขั้นตอนนี้ ทำเพียงครั้งเดียว

9. Commit ไฟล์ เพื่อเก็บ Version/Snapshot/Checkpoint (แล้วแต่จะเรียก) ของไฟล์
	git commit -m "Add a.txt"
    
     Option -m (message) เป็นการกำหนดว่าเราทำอะไรไว้กับไฟล์ ณ Checkpoint นี้
     สามารถ add หลายไฟล์เข้า staging area ก่อนจะ commit เพื่อสร้าง Checkpoint

10. แก้ไขไฟล์ a.txt และเพิ่มไฟล์ b.txt
      ตรวจสอบสถานะของไฟล์ ว่ามีการเปลี่ยนแปลงหรือไม่
	git status

11. เพิ่มไฟล์เข้า staging area สามารถใช้ . (dot) แทนชื่อไฟล์ เพื่อให้ add ทุกไฟล์ที่มีการเปลี่ยนแปลงใน directory ปัจจุบัน
	git add .
	git status

12. Commit ไฟล์ เพื่อเก็บ Checkpoint ของไฟล์
	git commit -m "Update a and add b"


13. ดู Checkpoint ทั้งหมด ด้วย git log adog
	git log --all --decorate --oneline --graph

     ตัวอย่างผลการทำงาน


	423cc2a เป็น commit id (เลขฐานสิบหก) 7 ตัวแรก เป็นหมายเลขอ้างอิง Checkpoint ซึ่งมาจากข้อมูลหลายส่วนประกอบกัน เช่น ชื่อผู้ commit, วันเวลาที่ commit, เนื้อหาในไฟล์, ...

ขั้นตอนที่ 1 ถึง 13 เป็นการทำงานบน local repository (git repository ที่อยู่บนเครื่องคอมพิวเตอร์ของตนเอง) 
เมื่อต้องการจะเก็บประวัติการทำงานไว้ที่ server (remote repository) (เพื่อทำงานร่วมกับผู้อื่น หรือเปลี่ยนเครื่องที่ใช้ทำงาน) ให้ทำตามขั้นตอนต่อไปนี้

14. สร้าง account ที่เป็น git server เช่น github, bitbucket
     ตัวอย่างนี้จะใช้ github.com
     ถ้ามี account อยู่แล้วให้ login

15. สร้าง repository ใหม่ บน github



16. กำหนดชื่อ repository แล้วกำหนดว่าเป็น Public repository หรือ Private repository 
     และไม่ต้องเลือก Initialize this repository with a README จากนั้นคลิกปุ่ม Create repository


17. เชื่อม local repository (git repo ในเครื่องเรา) กับ github ด้วยคำสั่ง 
git remote add <ชื่อ remote เช่น origin> <git url>

      ให้ดูตัวอย่างใน github ประกอบ

      หมายเหตุ ถ้าตั้งชื่อผิด ให้ลบชื่อเก่าก่อน ด้วยคำสั่ง git remote remove <ชื่อ remote> แล้วจึงใช้คำสั่ง git remote add … อีกครั้ง


18. เมื่อเชื่อม local ในเครื่อง กับ remote ที่ github ได้แล้ว ให้ส่งไฟล์และประวัติไปเก็บที่ github ด้วยคำสั่ง git push
	git push -u origin master

      origin คือ ชื่อ remote repository ที่เราตั้งขึ้นเอง ต้องตรงกับชื่อ remote ที่เราใช้คำสั่ง git remote add
      master คือ branch หลักที่ได้มาตั้งแต่ต้นจากการสร้าง git repository (ตอนสั่ง git init)
      -u คือ option ที่กำหนดไว้ว่า ในการใช้คำสั่ง git push ครั้งต่อไป ให้ push branch ใด ของ remote ใด

     เมื่อรันคำสั่ง push ครั้งแรก จะต้องใส่ username, password ของ github 
     ถ้าตอน push มี user อื่นใช้มาก่อนหน้า จะ push ไม่ได้ ให้ทำตามลิงก์นี้
Windows: https://cmatskas.com/how-to-update-your-git-credentials-on-windows)
Linux/MacOS: ใช้คำสั่ง    git config credential.username "new_username"

19. ตรวจสอบใน github ว่ามีไฟล์ขึ้นมาครบหรือไม่
     ตรวจสอบว่ามี Checkpoint เท่ากันกับในเครื่องของเราหรือไม่
     และตรวจสอบว่าแต่ละ Checkpoint มี commit id ตรงกับในเครื่องของเราหรือไม่

20. ตรวจสอบ Checkpoint ทั้งหมดในเครื่องของเรา จะเห็นว่า Checkpoint ของเราได้ถูกเก็บไว้ที่ origin/master ด้วย

	git log --all --decorate --oneline --graph

21. ประโยชน์อย่างหนึ่งของการใช้ git คือ สามารถนำ Checkpoint เก่ากลับมาทำงานได้ โดยทำได้ 2 แบบคือ

กลับมาทั้งหมด
	git checkout <commit-id>

กลับมาบางไฟล์
	git checkout <commit-id>  <ชื่อไฟล์>

22. ให้ลองแบบนำกลับมาบางไฟล์ก่อน โดยใช้คำสั่ง (<commit-id> เป็น commit-id อันแรกสุดเลย)

git checkout <commit-id> a.txt

(<commit-id> เป็น commit-id อันแรกสุดเลย) เช่น 
git checkout f0a9b41 a.txt

23. ลองเปิดไฟล์ a.txt มาอ่านว่าใช่ Checkpoint แรกหรือไม่

24. ถ้าต้องการใช้เวอร์ชันเก่านี้ สามารถ commit เพื่อเก็บและใช้เวอร์ชันเก่านี้ได้

git add .
git status
git commit -m "bring back a.txt from commit f0a9b41"

25. ตรวจสอบ log ของ Checkpoint จะเห็นว่า Checkpoint ใหม่อยู่บนสุดแล้ว โดย HEAD pointer จะชี้ไปที่ Checkpoint ใหม่ล่าสุดที่เครื่องเราใช้อยู่ และสังเกตด้วยว่า ที่ origin นั้น master ยังอยู่ที่เดิม


26. push ขึ้นไปที่ server github อีกครั้ง ด้วยคำสั่ง

	git push

       สังเกตว่าไม่ต้องใช้ -u อีก เนื่องจากจำไว้แล้วว่าจะ push ไปที่ origin/master

27. ตรวจสอบในเว็บ github อีกครั้งว่าไฟล์ขึ้นมาครบหรือไม่ Checkpoint ครบหรือไม่ 
      มี commit id ตรงกับในเครื่อง  local หรือไม่


28. เมื่อเปลี่ยนเครื่อง หรือลบ local repository ไปแล้ว อยากจะนำ git repository ที่เก็บไว้ใน server มาทำงานต่อ
      ให้ใช้คำสั่ง 
git clone <git-url>

       เช่น
	git clone https://github.com/saacsos/git101.git

       โดย git url หาได้จากปุ่ม Clone or download


          สามารถ clone public repository มาใช้งานได้ แต่จะ push ได้เฉพาะ repo ของตนเองเท่านั้น
