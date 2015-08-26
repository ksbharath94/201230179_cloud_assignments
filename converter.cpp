#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	ifstream ip;
	ofstream op;
	string line,line2;
	ip.open("hello_world_32.s");
	op.open("my64.s");
	if(ip.is_open())
	{
	 while(getline(ip,line))
	 {
	  cout<<line<<endl;
	  //op<<line<<endl;
	  
	  
	  if(line=="	.file	\"hello_world.c\"")
	  {
		cout<<"yay\n";
	   line2="	.file	\"hello_world.c\"";		 	
	  }
	  else if(line=="	.section	.rodata")
	  line2="	.section	.rodata";		 	
	  else if(line==".LC0:")
	  line2=".LC0:";		 	
	  else if(line=="	.string	\"%d\n\"")
	  line2="	.string	\"%d\n\"";		 	
	  else if(line=="	.text")
	  line2="	.text";		 	
	  else if(line=="	.globl	main")
	  line2="	.globl	main";		 	
	  else if(line=="	.type	main, @function")
	  line2="	.type	main, @function";		 	
	  else if(line=="main:")
	  line2="main:";		 	
	  else if(line==".LFB0:")
	  line2=".LFB0:";		 	
	  else if(line=="	.cfi_startproc")
	  line2="	.cfi_startproc";		 	
	  else if(line=="	pushl	%ebp")
	  {
	 // cout<<"yay\n";
	  line2="	pushq	%rbp";		 	
	  }
	  else if(line=="	.cfi_def_cfa_offset 8")
	  line2="	.cfi_def_cfa_offset 16";		 	
	  else  if(line=="	.cfi_offset 5, -8")
	  line2="	.cfi_offset 6, -16";		 	
	  else if(line=="	movl	%esp, %ebp")
	  line2="	movq	%rsp, %rbp";		 	
	  else if(line=="	.cfi_def_cfa_register 5")
	  line2="	.cfi_def_cfa_register 6";		 	
	  else if(line=="	andl	$-16, %esp")
	  line2="	subq	$16, %rsp";		 	
	  else if(line=="	subl	$32, %esp")
	  line2="	movl	$5, -12(%rbp)";		 	
	  else if(line=="	movl	$5, 20(%esp)")
	  line2="	movl	$3, -8(%rbp)";		 	
	  else if(line=="	movl	$3, 24(%esp)")
	  line2="	movl	-8(%rbp), %eax";		 	
	  else if(line=="	movl	24(%esp), %eax")
	  line2="	movl	-12(%rbp), %edx";		 	
	  else if(line=="	movl	20(%esp), %edx")
	  line2="	addl	%edx, %eax";
	  else if(line=="	addl	%edx, %eax")
	  line2="	movl	%eax, -4(%rbp)";
	  else if(line=="	movl	%eax, 28(%esp)")
	  line2="	movl	$.LC0, %eax";
	  else if(line=="	movl	$.LC0, %eax")
	  line2="	movl	-4(%rbp), %edx";
	  else if(line=="	movl	28(%esp), %edx")
	  line2="	movl	%edx, %esi";
	  else if(line=="	movl	%edx, 4(%esp)")
	  line2="	movq	%rax, %rdi";
	 else  if(line=="	movl	%eax, (%esp)")
	  line2="	movl	$0, %eax";
	  else if(line=="	call	printf")
	  line2="	call	printf";
	  else if(line=="	leave")
	  line2="	leave";
	  else if(line=="	.cfi_restore 5")
	  line2="	.cfi_def_cfa 7, 8";
	  else if(line=="	.cfi_def_cfa 4, 4")
	  line2="";
	  else if(line=="	ret")
	  line2="	ret";
	  else if(line=="	.cfi_endproc")
	  line2="	.cfi_endproc";
	  else line2=line;		
	
	 
	 
//	   if(line!="	.cfi_def_cfa 4, 4")
//	   {
	 	cout<<line2<<endl;
	 	op<<line2<<endl;
//	   }
	 }
	 ip.close();
	 op.close();
	}
	else cout<<"Cannot open input file\n";
	return 0;
}

