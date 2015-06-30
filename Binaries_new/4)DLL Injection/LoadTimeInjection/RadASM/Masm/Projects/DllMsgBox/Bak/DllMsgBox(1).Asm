.386
.model flat,stdcall
option casemap:none

include windows.inc
include user32.inc
include kernel32.inc
include user32.lib
includelib kernel32.lib

.data
AppName1         db "Windows format!",0
LoadMsg         db "Click OK to format your hard drive...",0


.code
DllEntry proc hInstance:HINSTANCE, reason:DWORD, reserved1:DWORD
	
	; DLLloaded
	.if reason==DLL_PROCESS_ATTACH
		invoke MessageBox,NULL,addr LoadMsg,addr AppName1,MB_OK
	.endif
	
	mov  eax,TRUE
	ret

DllEntry endp

TestProc proc

	invoke MessageBox,NULL,addr LoadMsg,addr AppName1,MB_OK
	ret	
TestProc endp

End DllEntry