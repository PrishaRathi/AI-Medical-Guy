// -----------------------------------------------------------------------------
// --- ExpertSystem (MedicalExpert)
// --- Written By Prisha Rathi [13-APR-2014]
// -----------------------------------------------------------------------------
// --- Expert System for dignosing the diseases based on symptoms
// -----------------------------------------------------------------------------
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <memory.h>
#include <string.h>
// -----------------------------------------------------------------------------
#include "Database.h"
// -----------------------------------------------------------------------------
#define VERSION "V 1.0"
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// --- global definitions
int g__num_symptoms;
int g__num_diseases;
char g__patient[ 64 ];
int g__valid_symptoms_collection[ MAX_SYMPTOMS ];
int g__num_valid_symptoms;
int g__invalid_symptoms_collection[ MAX_SYMPTOMS ];
int g__num_invalid_symptoms;
// -----------------------------------------------------------------------------



// -----------------------------------------------------------------------------
// --- helper function prototypes
// -----------------------------------------------------------------------------
void InitialGreetings();
void FarewellGreetings();
void ComplicatedDiseaseMessage();
void DiagnosisMessage( int disease_idx );
int GetNextSymptomToCheck();
bool IsSymptomAlreadyChecked( int symptom_idx );
void CheckSymptom( int symptom_idx );
int CheckForDisease();
// -----------------------------------------------------------------------------



// -----------------------------------------------------------------------------
int main(int argc, char* argv[])
{
    // --- lets first find out how many symptoms and diseases we have and can we handle them..
    g__num_symptoms = sizeof( g__symptoms ) / sizeof( g__symptoms[ 0 ] );
    g__num_diseases = sizeof( g__disease ) / sizeof( g__disease[ 0 ] );
    if( ( g__num_symptoms >= MAX_SYMPTOMS ) || ( g__num_diseases >= MAX_DISEASES ) )
    {
        printf( "Oops! Well, this is emberassing!\n" );
        printf( "I have more symptoms or diseases in my database than I can handle!!!\n" );
        printf( "Please report this to my programmer to fix me!!\n" );
        printf( "I am extremely sorry that I couldn't help you! Goodbye!!" );
        printf( "\n\n" );
        return( -1 );
    }



    // --- initialize our symptoms collection
    int loop_cnt;
    for( loop_cnt = 0; loop_cnt < MAX_SYMPTOMS; loop_cnt++ )
    {
        g__valid_symptoms_collection[ loop_cnt ] = g__invalid_symptoms_collection[ loop_cnt ] = -1;
    }
    g__num_valid_symptoms = g__num_invalid_symptoms = 0;




    // --- let's get the ball rolling...
    InitialGreetings();
    srand( (unsigned)time( NULL ) );



    // --- loop through the symptoms
    while( true )
    {
        // --- let's check with the patient for the next symptom
        int next_symptom_idx = GetNextSymptomToCheck();
        if( next_symptom_idx < 1 )
        {
            // --- we ran out of symptoms
            // --- may be the disease is too complicated for us to handle...
            ComplicatedDiseaseMessage();
            break;
        }


        // --- check for the symptom
        CheckSymptom( next_symptom_idx );


        // --- see if we can diagnose based on the symptoms collected so far
        int l_disease_idx = CheckForDisease();
        if( l_disease_idx > 0 )
        {
            DiagnosisMessage( l_disease_idx );
            break;
        }
    }



    // --- farewell greetings
    FarewellGreetings();
    return( 0 );
}
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
void InitialGreetings()
{
    // --- start the conversation
    printf( "\n" );
    printf( "Hello! My name is HAL9000. I am your medical expert [%s]\n", VERSION );
    printf( "What's your name?\n" );
    gets( g__patient );
    printf( "\n" );
    printf( "Hello %s! How are you today? Let's see what's bothering you...\n", g__patient );
}
// -----------------------------------------------------------------------------
void FarewellGreetings()
{
    // --- say goodbye...
    char s[ 64 ];
    printf( "\n" );
    printf( "Get well soon %s! Goodbye!!\n", g__patient );
    printf( "Press ENTER key to exit...\n" );
    gets( s );
}
// -----------------------------------------------------------------------------
void ComplicatedDiseaseMessage()
{
    // --- the disease is too complicated for us to handle...
    // --- say goodbye...
    printf( "\n" );
    printf( "Sorry %s! Your symptoms are too complicated for me to handle...\n", g__patient );
    printf( "May be its time for you to see your family physician...\n" );
}
// -----------------------------------------------------------------------------
void DiagnosisMessage( int disease_idx )
{
    // --- we have found a probable disease
    printf( "\n" );
    printf( "%s! Looks like you may be suffering from %s\n", g__patient, g__disease[ disease_idx ].m_name );
}
// -----------------------------------------------------------------------------
int GetNextSymptomToCheck()
{
    // --- we will get a random symptom to check
    // --- making sure that this symptom has not been asked already
    int i;


    // --- first see how many symptoms have we collected?
    // --- if we have collected more than half of total symptoms, then we
    // --- will just find out the first available symptom that we haven't
    // --- yet checked and use it
    if( ( g__num_valid_symptoms + g__num_invalid_symptoms ) >= ( g__num_symptoms / 2 ) )
    {
        // --- we always start with symptom 1 because we don't want to check S_NONE
        for( i = 1; i < g__num_symptoms; i++ )
        {
            if( IsSymptomAlreadyChecked( i ) )
            {
                continue;
            }

            // --- we have found a symptom we would like to check next
            return( i );
        }

        // --- we have checked all the symptoms
        return( -1 );
    }



    // --- get a random number that is within our symptom database
    while( true )
    {
        int l_symptom_idx = rand();
        if( ( l_symptom_idx >= g__num_symptoms ) || ( l_symptom_idx == 0 ) )
        {
            continue;
        }

        // --- let's see if this randomly selected symptom is already checked
        if( IsSymptomAlreadyChecked( l_symptom_idx ) )
        {
            continue;
        }

        // --- we found a symptom we want to check next
        return( l_symptom_idx );
    }


    // --- we should never get here, but just to keep the compiler happy
    return( -1 );
}
// -----------------------------------------------------------------------------
bool IsSymptomAlreadyChecked( int symptom_idx )
{
    // --- let's find out if we have already checked this symptom
    int l_symptom = g__symptoms[ symptom_idx ].m_code;
    bool found = false;
    int i;


    // --- check through the collection of symptoms that patient is already suffering
    for( i = 0; i < g__num_valid_symptoms; i++ )
    {
        if( l_symptom == g__valid_symptoms_collection[ i ] )
        {
            found = true;
            break;
        }
    }
    if( found )
    {
        return( true );
    }

    
    // --- check through the collection of symptoms that patient is not suffering
    for( i = 0; i < g__num_invalid_symptoms; i++ )
    {
        if( l_symptom == g__invalid_symptoms_collection[ i ] )
        {
            found = true;
            break;
        }
    }
    if( found )
    {
        return( true );
    }


    // --- looks like this is a symptom we haven't checked yet
    return( false );
}
// -----------------------------------------------------------------------------
void CheckSymptom( int symptom_idx )
{
    printf( "\n" );
    printf( "%s", g__symptoms[ symptom_idx ].m_question );
    printf( "\n" );

    // --- check for the answer
    while( true )
    {
        char answer[ 64 ];
        memset( answer, 0, sizeof( answer ) );
        gets( answer );
        if( _stricmp( answer, "yes" ) == 0 )
        {
            // --- record this symptom
            g__valid_symptoms_collection[ g__num_valid_symptoms++ ] = symptom_idx;
            return;
        }
        if( _stricmp( answer, "no" ) == 0 )
        {
            // --- record this symptom
            g__invalid_symptoms_collection[ g__num_invalid_symptoms++ ] = symptom_idx;
            return;
        }
        printf( "\n" );
        printf( "Well %s,\nI don't understand anything more complicated than yes or no yet :(\n", g__patient );
        printf( "Please answer yes or no..." );
        printf( "\n" );
        printf( "%s", g__symptoms[ symptom_idx ].m_question );
        printf( "\n" );
    }
}
// -----------------------------------------------------------------------------
int CheckForDisease()
{
    // --- lets go through all diseases and see which one matches our collected symptoms
    int i, j, k;
    for( i = 1; i < g__num_diseases; i++ )
    {
        // --- check the symptoms for this disease
        int valid_symptoms = 0;
        for( j = 0; g__disease[ i ].m_symptoms[ j ] > 0; j++ )
        {
            // --- loop through our collected symptoms and see if they match
            for( k = 0; k < g__num_valid_symptoms; k++ )
            {
                if( g__disease[ i ].m_symptoms[ j ] == g__valid_symptoms_collection[ k ] )
                {
                    valid_symptoms++;
                }
            }
        }

        // --- did we get minimum number of symptoms for this disease?
        if( valid_symptoms >= g__disease[ i ].m_min_symptoms )
        {
            // --- we found the matching disease
            return( i );
        }
    }


    // --- well, we couldn't find a matching disease for these collection of symptoms
    return( -1 );
}
// -----------------------------------------------------------------------------
