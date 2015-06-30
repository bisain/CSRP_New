#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <intrin.h>
#include <stdio.h>


DWORD WINAPI MyThreadFunction0( LPVOID lpParam );
DWORD WINAPI MyThreadFunction1( LPVOID lpParam );

DWORD WINAPI MyThreadFunction0( LPVOID lpParam ) 
{ 

    unsigned char* ptr = (unsigned char*)(&MyThreadFunction1);
	int i = 0;
	int id;
    id = (int)lpParam;
   
	ptr['\x7']--; 

	__asm{jmp [MyThreadFunction1]}

    return 0; 
} 
 
DWORD WINAPI MyThreadFunction1( LPVOID lpParam ) 
{ 
 
	int id;
    id = (int)lpParam;
	
	if(id == 1)
		printf("%d:you lose!",id);
	else
		printf("%d:you win!",id);
   

    return 0; 
} 

int main()
{
    
	

    // Spawn the threads
    HANDLE thread1, thread2;
    thread1 = CreateThread(NULL, 0, MyThreadFunction0, NULL, 0, NULL);
    thread2 = CreateThread(NULL, 1, MyThreadFunction1, NULL, 0, NULL);



    Sleep(5000);

    return 0;  // Never returns
}


