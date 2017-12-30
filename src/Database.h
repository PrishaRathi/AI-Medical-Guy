// -----------------------------------------------------------------------------
// --- ExpertSystem (MedicalExpert)
// --- Written By Prisha Rathi [16-APR-2014]
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
    S_ITCHING_HEAD,
    S_NITS,
    S_DIFFICULTY_SLEEPING,
    S_FEVER,
    S_EAR_PAIN,
    S_ITCHING_EAR,
    S_LOSS_OF_APPETITE,
    S_THICK_YELLOW_FLUID_FROM_EARS,
    s_RUNNY_NOSE,
    s_SINUS_PRESSURE,
    S_POST_NASAL_DRIP,
    S_STUFFY_NOSE,
    S_SNEEZING,
    S_TROUBLE_BREATHING,
    S_WHEEZING,
    s_DIZZINESS,
    S_CHEST_PAIN,
    S_COUGHING_BLOOD,
    s_LOUD_NOISES_WHILE_BREATHING,
    s_LABOURED_BREATHING,
    S_WATERY_DIARRHEA,
    S_VOMITING,
    S_NAUSEA
};
// --- enumeration of all the diseases
typedef enum DISEASE
{
    D_NONE,
    D_HEAD_LICE,
    D_EAR_INFECTION,
    D_NASAL_CONGESTION,
    D_CHEST_CONGESTION,
    D_FOOD_POISONING
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
    { S_NONE, "No Symptom", "Don't you have any discomfort?" },

    { S_ITCHING_HEAD, "Itching Head", "Does your head itch?" },

    { S_NITS, "Nits", "Have you found little white eggs in your hair?" },

    { S_DIFFICULTY_SLEEPING, "Difficulty Sleeping", "Is it hard to sleep sometimes?" },

    { S_FEVER, "Fever", "Do you have a fever?" },
    
    { S_EAR_PAIN, "Ear Pain", "Does your ear hurt?" },

    { S_ITCHING_EAR, "Itching Ear", "Do you experience itchy ears?" },

    { S_LOSS_OF_APPETITE, "Loss Of Appetite", "Have you felt a loss of appetite?" },

    { S_THICK_YELLOW_FLUID_FROM_EARS, "Thick Yellow Fluid From Ears", "Do you see yellow fluid/liquid coming out of your ear?" },

    { s_RUNNY_NOSE, "Runny Nose", "Do you have a runny nose?" },

    { s_SINUS_PRESSURE, "Sinus Pressure", "Do you feel pressure in your sinus/inner nose?" },

    { S_POST_NASAL_DRIP, "Post Nasal Drip", "Does your nose drip?" },

    { S_STUFFY_NOSE, "Stuffy Nose", "Do you have a stuffy nose?" },

    { S_SNEEZING, "Sneezing", "Have you been sneezing a lot recently?" },

    { S_TROUBLE_BREATHING, "Trouble Breathing", "Is it hard to breathe?" },

    { S_WHEEZING, "Wheezing", "Have you been wheezing a lot lately?" },

    { s_DIZZINESS, "Dizziness", "Do you feel dizzy?" },

    { S_CHEST_PAIN, "Chest Pain", "Do you experience chest pain?" },

    { S_COUGHING_BLOOD, "Coughing Blood", "Is there blood in your cough?" },

    { s_LOUD_NOISES_WHILE_BREATHING, "Loud Noise While Breathing", "Do you make loud noises while breathing?" },

    { s_LABOURED_BREATHING, "Laboured Breathing", "Do you find it hard to breathe?" },

    { S_WATERY_DIARRHEA, "Watery Diarrhea", "Is your feces watery?" },

    { S_VOMITING, "Vomiting", "Have you vomitied?" },

    { S_NAUSEA, "Nausea", "Do you feel naucious?" }
};

disease g__disease[] = 
{
    { D_NONE, "No Disease", { S_NONE }, 0 },
    { D_HEAD_LICE, "Head Lice", { S_NITS, S_ITCHING_HEAD }, 2 },
    { D_EAR_INFECTION, "Ear Infection", { S_THICK_YELLOW_FLUID_FROM_EARS, S_EAR_PAIN, S_ITCHING_EAR, S_FEVER, S_LOSS_OF_APPETITE, S_DIFFICULTY_SLEEPING }, 3 },
    { D_NASAL_CONGESTION, "Nasal Congestion", { s_SINUS_PRESSURE, s_RUNNY_NOSE, S_POST_NASAL_DRIP, S_STUFFY_NOSE, S_SNEEZING }, 3 },
    { D_CHEST_CONGESTION, "Chest Congestion", { S_COUGHING_BLOOD, S_CHEST_PAIN, s_LOUD_NOISES_WHILE_BREATHING, s_LABOURED_BREATHING, s_DIZZINESS, S_WHEEZING }, 4 },
    { D_FOOD_POISONING, "Food Poisoning", { S_WATERY_DIARRHEA, S_VOMITING, S_NAUSEA }, 2 }
};
// -----------------------------------------------------------------------------
