Program #3

Name: Beckham Carver

COSC 2030

Competing: YES!

Best run time: 0.71 on HIVE machines

How to compile: g++ prog3.cpp

Anything that doesn't work: Everything works properly, you can even set the hashsize to 1 and use it as a horrible linked list.

---
grading 96/100<BR>
* github, compiles, and  run (10 points ) yes
* cover page correct (2 points) yes
* readme updated and correct (2 points) yes
* "data structure" is hash function (25 points) almost
  * if new, then delete
  * linked list.
  * destructor problems.  while you erase the array, you don't actually delete any of the nodes, you would need to loop though the array, deleting all the nodes, then delete the array.  so you orphaned all of nodes.  -4
    * why didn't you use your linked list code isntead of recreating it?
* cleaword method (12 points) yes
* read dictionary (5 points) yes
  * calls clean word
* reads book (5 points) yes
  * calls clean word
* skipped correct (5 points) yes
* spelling checking code correct (10 points) yes
* compare counts are correct (10 points) yes
* format/output correct (10 points) yes
  * spelled and misspelled
  * misspelled file? yes
* timing code and run time (4 points) yes
* competeing, gears:  5

and Notes:<BR>
* compiles and runs.  pi time is 3.2  
