;SpyFunc v1.0 by Gabri3l [ARTeam]
;Supplement to Weakness of Windows API Tutorial
;
;---------------------------------------------------------------------------------------------
;When the DLL is loaded the specified function is overwritten by an infinite loop
;Can be used by calling LoadLibrary or defining the DLL in APP_INIT Registry Key
;*********************************************************************************************
;**This is very beta code, it can screw up your system if you are not careful, so be careful**
;**                                                                                         **
;**            BTW: Thanks to Human and rukiddin for their help!                            **
;*********************************************************************************************
;
;Any questions or comments: Visit us at http://cracking.accessroot.com
;---------------------------------------------------------------------------------------------


.586                                               ;for 586 processor or better
.model flat, stdcall                               ;32-bit memory and standard call

;Function Includes
;-------------------------------------
include    C:\masm32\include\windows.inc
include    C:\masm32\include\kernel32.inc
includelib C:\masm32\lib\kernel32.lib
;--------------------------------------
SpyReplace  PROTO                                 ;Prototype for our replace function                                ;Prototype for our test function

.data                                             ;Defined Data
nDll         db "user32.dll",0                    ;DLL to Hook
nProc        db "MessageBoxA",0                   ;Function to Hook
nRedirect    db "Spyfunc.dll",0                   ;DLL to Redirect to
nFunc        db "SpyReplace",0                    ;Function to Redirect to
nSize        dd 069000h                           ;Size of the DLL
nIncrement   dd 0Ch                               ;Amount to increment the stack by to point to our argument to be modified
nReplaceWith db "The function has been modified",0;replacement text for modified function argument
nTest1       db "This is a test"                  ;Known argument to test out our modified function
nTest2       db "Test"                            ;Known argument to test out our modified function


.data?                                            ;Undefined Data
nAddress     dd ?                                 ;Address of the DLL when loaded into memory
nLoc         dd ?                                 ;Location of Function to Hook
nOldProt     dd ?                                 ;Old Protection of DLL
nRedirectAddress dd ?                             ;Address of the DLL to redirect to
nRedirectLoc     dd ?                             ;Location of Function to redirect to
nOldBytesOne     dd ?                             ;Old Bytes of overwritten function   
nOldBytesTwo     dd ?                             ;Another buffer to hold overwritten bytes
nTopOfStack      dd ?                             ;Hold the value at the top of the stack. 

.code                                             ;the beginning of the code section
LibMain proc h:DWORD, r:DWORD, u:DWORD            ;the dll entry point
        INVOKE LoadLibrary, ADDR nDll             ;Load the DLL to be hooked
        mov nAddress, eax                         ;Move Location of DLL into nAddress
        INVOKE GetProcAddress,nAddress,ADDR nProc ;Get the Address of the function to be hooked
        mov nLoc, eax                             ;Move Function location into nLoc
        INVOKE VirtualProtect,nAddress,nSize,PAGE_EXECUTE_READWRITE,OFFSET nOldProt ;Grant Read/Write access to DLL
        INVOKE LoadLibrary, ADDR nRedirect        ;Load the DLL to be hooked
        mov nRedirectAddress, eax                 ;Move Location of DLL into nRedirectAddress
        INVOKE GetProcAddress,nRedirectAddress,ADDR nFunc ;Get the Address of the function to be redirected to
        mov nRedirectLoc, eax                     ;Move Function location into nRedirectLoc
        MOV EAX, DWORD PTR DS:[nLoc]              ;Move address of function into EAX
        PUSH ECX                                  ;Push ECX to keep Register integrity
        mov ECX, DWORD PTR DS:[EAX]               ;Move Old bytes of the function into ECX
        MOV nOldBytesOne, ECX                     ;Move Old bytes of the function into buffer
        ADD EAX, 4                                ;Increment by 4 to read next bytes
        mov ECX, DWORD PTR DS:[EAX]               ;Move Old bytes of the function into ECX
        MOV nOldBytesTwo, ECX                     ;Move Old bytes of the function into ECX
        SUB EAX, 4                                ;Subtract 4 to restore EAX
        mov BYTE PTR DS:[EAX], 0E9h               ;Write the JMP command into the function
        MOV ECX, nRedirectLoc                     ;Move address of Redirected function into ECX
        ADD EAX, 5                                ;Increment EAX to move to end of operands
        Sub ECX, EAX                              ;Subtract Calling Address from Address to be called
        SUB EAX, 4                                ;Increment EAX to point to BYTES directly after JMP Command
        mov DWORD PTR DS:[EAX], ECX               ;Write new function location after CALL command
        POP ECX                                   ;Restore ECX
        mov eax, 1                                ;Set EAX to 1 so the DLL will initialize
        ret                                       ;return
LibMain Endp                                      ;end of the dll entry


SpyReplace proc                                   ;The function to replace the MessageBox text with our own 
PUSH ECX                                          ;Push ECX to preserve integrity
MOV nTopOfStack,ESP                               ;Push the address of the top of the stack into nTopOfStack
MOV EAX, nIncrement                               ;Add 12 (0Ch) to EAX to move it to the old argument of the stack
ADD EAX, nTopOfStack                              ;Add the value of the top of the stack to EAX
MOV ECX, OFFSET nReplaceWith                      ;Move the address location of our replacement text to ECX
MOV DWORD PTR DS:[EAX], ECX                       ;Move the replacement text address into the stack overwriting the old arguement
MOV EAX, DWORD PTR DS:[nLoc]                      ;Move address of function into EAX
MOV ECX, nOldBytesOne                             ;Move the old function bytes into ECX
MOV Dword PTR DS:[EAX],ECX                        ;Restore the first bytes of the modified function
ADD EAX,4                                         ;Increment ECX by 4 to move to the next 4 bytes
MOV ECX, nOldBytesTwo                             ;Move the next old function bytes into ECX
MOV Dword PTR DS:[EAX],ECX                        ;Restore the final bytes of our modified function
Sub EAX,4                                         ;Decrement ECX by 4 so it contains the Address of the beginning of our restored function
POP ECX                                           ;Restore ECX
JMP EAX                                           ;Jump to the beginning of our restored function
ret                                               ;Return (not used)
SpyReplace endp                                   ;End of replacement function
 
End LibMain                                       ;end of the dll 

