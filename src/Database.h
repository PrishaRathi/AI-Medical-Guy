// -----------------------------------------------------------------------------
// --- ExpertSystem (MedicalExpert)
// --- Written By Prisha Rathi [13-APR-2014]
// -----------------------------------------------------------------------------
// --- Expert System for dignosing the diseases based on symptoms
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// --- global definitions
#define MAX_SYMPTOMS                    100
#define MAX_DISEASES                    100
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// --- data structures
// -----------------------------------------------------------------------------
// --- enumeration of all the symptoms
typedef enum SYMPTOM
{
    S_NONE,
    S_COUGH,
    S_FEVER
};
// --- enumeration of all the diseases
typedef enum DISEASE
{
    D_NONE,
    D_FEVER
};

// --- symptom data structure
typedef struct 
{
    int m_code;                             // --- symptom code
    char m_name[ 32 ];                      // --- symptom name
    char m_question[ 64 ];                  // --- question to ask
} symptom;

// --- disease data structure
typedef struct 
{
    int m_code;                             // --- disease code
    char m_name[ 32 ];                      // --- disease name
    int m_symptoms[ MAX_SYMPTOMS ];         // --- symptoms for this disease
    int m_min_symptoms;                     // --- minimum compulsory symptoms
} disease;
// -----------------------------------------------------------------------------
symptom g__symptoms[] = 
{
    { S_NONE, "No Symtom", "Don't you have any discomfort?" },
    { S_COUGH, "Cough", "Do you cough frequently?" }
};

disease g__disease[] = 
{
    { D_NONE, "No Disease", { S_NONE }, 0 },
    { D_FEVER, "Fever", { S_COUGH, S_FEVER }, 1 },
};
// -----------------------------------------------------------------------------
