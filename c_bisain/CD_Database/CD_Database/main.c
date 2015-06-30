#include <stdio.h>      // declares printf(), scanf() and fpurge().
#include <stdbool.h>    // declares bool.
#include <string.h>     // declares strcmp().
#include <stdlib.h>     // We'll need that later for malloc() and realloc().

// Data structure:
struct CDDatabaseEntry
{
    char    artist[40];
    char    composer[40];
    char    albumName[40];
    int     trackCount;
    bool    isSampler;
};


// Global variables:
int                        gNumDatabaseEntries = 0;
struct CDDatabaseEntry*    gDatabase = NULL;


void DoNewCommand();

void DoNewCommand()
{
    char yesOrNo;
    
    // First, create a new array element (or a new array if we don't have one yet):
    if( gDatabase == NULL )
    {
        gDatabase = malloc( sizeof(struct CDDatabaseEntry) ); // size of 1 element.
        if( gDatabase == NULL )    // Still NULL? malloc() must have returned NULL due to error.
        {
            printf( "ERROR: Couldn't create a new entry!\n" );
            return;
        }
    }
    else
    {
        struct CDDatabaseEntry* newPtr = NULL;
        newPtr = realloc( gDatabase, (gNumDatabaseEntries +1) *sizeof(struct CDDatabaseEntry) );
        if( newPtr == NULL )    // Error! Out of memory?
        {
            // We just keep the old pointer in gDatabase.
            printf( "ERROR: Couldn't create a new entry!\n" );
            return;
        }
        // newPtr is our new ptr, gDatabase is no longer valid!
        gDatabase = newPtr;    // Remember newPtr in gDatabase.
    }
    
    // Make sure we remember we have one more entry:
    gNumDatabaseEntries += 1;
    
    // Now replace the garbage data in the new, last entry with data the user entered:
    printf( "Artist Name: " );
    scanf( "%39s", gDatabase[ gNumDatabaseEntries -1 ].artist );
    fpurge( stdin );
    
    printf( "Composer: " );
    scanf( "%39s", gDatabase[ gNumDatabaseEntries -1 ].composer );
    fpurge( stdin );
    
    printf( "Album Name: " );
    scanf( "%39s", gDatabase[ gNumDatabaseEntries -1 ].albumName );
    fpurge( stdin );
    
    printf( "No. of Tracks: " );
    scanf( "%d", &gDatabase[ gNumDatabaseEntries -1 ].trackCount );
    fpurge( stdin );
    
    printf( "Sampler? (y/n): " );
    scanf( "%c", &yesOrNo );
    fpurge( stdin );
    
    gDatabase[ gNumDatabaseEntries -1 ].isSampler = (yesOrNo == 'y' || yesOrNo == 'Y');
}


void DoListCommand();

void DoListCommand()
{
    int    x = 0;
    
    if( gDatabase == NULL )
    {
        printf("There are no CDs in the database.\n");
        return;
    }
    
    while( x < gNumDatabaseEntries )
    {
        printf( "Artist Name: %s\n", gDatabase[ x ].artist );
        printf( "Composer: %s\n", gDatabase[ x ].composer );
        printf( "Album Name: %s\n", gDatabase[ x ].albumName );
        printf( "No. of Tracks: %d\n", gDatabase[ x ].trackCount );
        if( gDatabase[ x ].isSampler )
            printf( "\tThis CD is a sampler.\n" );
        printf( "\n" );    // Add an empty line for space to the next CD.
        
        x += 1;
    }
}


void    DoCleanUp( void );

void    DoCleanUp( void )
{
    if( gDatabase != NULL )    // We have allocated memory?
    {
        free( gDatabase );
        gDatabase = NULL;                // Not really necessary, but good style.
        gNumDatabaseEntries = 0;
    }
}


// Main event loop:
// Fetches user input and calls our DoXXX functions to do the work.
int main()
{
    bool keepRunning = true;
    char userInput[11];
    
    while( keepRunning == true )
    {
        printf( "Type NEW , LIST, or QUIT:\n> " );
        scanf( "%10s", userInput );
        fpurge( stdin );
        
        if( strcmp( userInput, "NEW" ) == 0 )
            DoNewCommand();
        else if( strcmp( userInput, "LIST" ) == 0 )
            DoListCommand();
        else if( strcmp( userInput, "QUIT" ) == 0 )
            keepRunning = false; // We're finished.
        else
            printf( "ERROR: Unknown command \"%s\"!\n\n", userInput );
    }
    
    DoCleanUp();
    
    return 0;
}