// -----------------------------------------------------------------------------
// --- ExpertSystem (MedicalExpert)
// --- Written By Prisha Rathi [18-APR-2014]
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
    S_BLOATING,
    S_PAIN_IN_BELLY_OR_PELVIS,
    S_SPOTS_OR_COATING_ON_THROAT_AND_TONSILS,
    S_SWOLLEN_LYMPH_NODES,
    S_THICKENING_OF_THE_SKIN,
    S_GRUMPY_OR_CRANKY,
    S_TROUBLE_CONCENTRATING,
    S_HEAD_PAIN,
    S_PEELING_OR_CRACKING_OR_SCALING_OF_FOOT,
    S_LOUD_NOISES_WHILE_BREATHING,
    S_ABDOMINAL_PAIN_AND_CRAMPS,
    S_CROWDING_OF_OTHER_TEETH,
    S_CHANGE_IN_JAW_ALIGNMENT,
    S_BROKEN_BONES_OR_FRACTURES,
    S_CHEST_DISCOMFORT_OR_PAIN,
    S_COUGH,
    S_CONSTIPATION,
    S_POST_NASAL_DRIP,
    S_PAIN_AROUND_PIERCING,
    S_PAIN_AROUND_TATTOO,
    S_PAIN_AROUND_STING,
    S_PAIN_AROUND_EAR,
    S_THROAT_PAIN,
    S_PAIN,
    S_NOT_HEALING_PROPERLY,
    S_NITS,
    S_NAUSEA,
    S_DIZZINESS,
    S_DIAPER_RASH,
    S_IRRITATION_OF_THE_EYE,
    S_BLOOD_IN_COUGH,
    S_BLEEDING_GUMS_AFTER_BRUSHING,
    S_BAD_SMELL,
    S_BODY_ACHES,
    S_FEVER,
    S_DEHYDRATION,
    S_BRIGHT_RED_THROAT,
    S_LOSS_OF_HEIGHT,
    S_INSTANT_SHARP_BURNING_PAIN,
    S_HEAVY_BLEEDING_DURING_PERIODS,
    S_LOSS_OF_BREATH,
    S_HEADACHE,
    S_LOSS_OF_APPETITE,
    S_BAD_POSTURE,
    S_BLISTERS,
    S_CHILLS,
    S_ITCHY_EYE_OR_DISCOMFORT_OR_PAIN,
    S_DROOLING,
    S_ITCHINESS,
    S_INDENTATION_OF_THE_TATTOO,
    S_FATIGUE,
    S_BAD_BREATH_OR_TASTE_IN_MOUTH,
    S_DIARRHEA,
    S_PALENESS,
    S_LABORED_BREATHING,
    S_VOMITING,
    S_SNEEZING,
    S_WHEEZING,
    S_TOOTH_DECAY,
    S_RUNNY_NOSE,
    S_RASH,
    S_SWELLING,
    S_SORE_THROAT,
    S_MUSCLE_ACHES,
    S_STUFFY_NOSE,
    S_RECEDING_GUMS,
    S_PUS_OR_DRAINAGE,
    S_RED_BUMPS,
    S_RED_AREAS,
    S_RED_HAZE,
    S_SINUS_PRESSURE,
    S_SENSITIVITY_TO_LIGHTS_NOISE_OR_ODOURS,
    S_DEEP_POCKETS_BETWEEN_TEETH_AND_GUMS,
    S_BACK_PAIN,
    S_THICK_YELLOW_FLUID_COMING_FROM_EARS,
    S_FLUSHED_CHEEKS,
    S_TENDENCY_TO_CHEW_ON_HANDS,
    S_PAIN_FROM_TEETH 
};
// --- enumeration of all the diseases
typedef enum DISEASE
{
    D_NONE,
    D_HEARTBURN,
    D_MEASLES,
    D_GINGIVITIS,    
    D_A_BEE_STING, 
    D_MONONUCLEOSIS, 
    D_OSTEOPOROSIS,
    D_ANEMIA,
    D_MIGRAINE,
    D_UTERINE_FIBROIDS,
    D_PINK_EYE,      
    D_CHICKEN_POX,
    D_INFECTED_TATTOO,
    D_EAR_INFECTION,
    D_NASAL_CONGESTION,
    D_CHEST_CONGESTION,    
    D_ATHLETE_FOOT,
    D_WISDOM_TEETH,
    D_BRONCHITIS,
    D_INGROWN_TOENAIL,
    D_ECZEMA,
    D_ASTHMA,
    D_TEETHING_IN_BABIES,
    D_STREP_THROAT,
    D_INFECTED_PIERCING,
    D_FLU,
    D_STOMACH_FLU,
    D_FOOD_POISONING,
    D_HEAD_LICE        
};

// --- symptom data structure
typedef struct 
{
    int m_code;                             // --- symptom code
    char m_name[ 64 ];                      // --- symptom name
    char m_question[ 128 ];                 // --- question to ask
} symptom;

// --- disease data structure
typedef struct 
{
    int m_code;                             // --- disease code
    char m_name[ 32 ];                      // --- disease name
    int m_symptoms[ MAX_SYMPTOMS ];         // --- symptoms for this disease
    int m_min_symptoms;                     // --- minimum valid symptoms
    int m_mandatory_symptoms;               // --- minimun complusory symptoms 
    char m_treatment[ 2048 ];               // --- treatments
} disease;
// -----------------------------------------------------------------------------
symptom g__symptoms[] = 
{
    { S_NONE, "No Symptom", "Don't you have any discomfort?" },

    { S_PAIN_IN_BELLY_OR_PELVIS, "Pain in belly or pelvis", "Do you feel any pain in your belly or pelvis?" },

    { S_SPOTS_OR_COATING_ON_THROAT_AND_TONSILS, "Spots, or coating on throat and tonsils", "Have you seen spots or a coating on your throat and tonsils?" },

    { S_SWOLLEN_LYMPH_NODES, "Swollen lymph nodes", "Are your lymph nodes swollen?" },

    { S_BLOATING, "Bloating", "Does any part of your body feel bloated?" },
    
    { S_THICKENING_OF_THE_SKIN, "Thickening of the skin", "Does your skin thicken?" },

    { S_GRUMPY_OR_CRANKY, "Grumpy or cranky", "Have you been feeling grumpy or cranky lately?" },

    { S_TROUBLE_CONCENTRATING, "Trouble concentrating", "Do you have trouble concentrating lately?" },

    { S_HEAD_PAIN, "Head pain", "Does your head hurt?" },

    { S_PEELING_OR_CRACKING_OR_SCALING_OF_FOOT, "Peeling, cracking, or scaling, of the foot", "Are your feet peeling, cracking, or scaling whatsoever?" },

    { S_LOUD_NOISES_WHILE_BREATHING, "Loud noises while breathing", "Do you make loud noises while breathing?" },

    { S_ABDOMINAL_PAIN_AND_CRAMPS, "Abdominal pain and cramps", "Do you experience any abdominal pain or cramps?" },

    { S_CROWDING_OF_OTHER_TEETH, "Crowding of other teeth", "Do your teeth crowd?" },

    { S_CHANGE_IN_JAW_ALIGNMENT, "Change in jaw alignment", "Has your jaw alignment changed?" },

    { S_BROKEN_BONES_OR_FRACTURES, "Broken bones and fractures", "Have any of your bones been broken of fractured recently?" },

    { S_CHEST_DISCOMFORT_OR_PAIN, "Chest discomfort or pain", "Do you experience any discomfort or pain in your chest?" },

    { S_COUGH, "Cough", "Have you been coughing a lot recently?" },

    { S_CONSTIPATION, "Constipation", "Have you been experiencing constipation recently?" },

    { S_POST_NASAL_DRIP, "Post nasal drip", "Does your nose drip a lot?" },

    { S_PAIN_AROUND_PIERCING, "Pain around piercing", "Do you feel any pain around your piercing (if you have one)?" },

    { S_PAIN_AROUND_TATTOO, "Pain around tattoo", "Do you experience pain around your tattoo (if you have one)?" },

    { S_PAIN_AROUND_STING, "Pain around sting", "Do you feel pain around your sting?" },

    { S_PAIN_AROUND_EAR, "Pain around ear", "Do your ears hurt?" },

    { S_THROAT_PAIN, "Throat pain", "Does your throat hurt?" },

    { S_PAIN, "Pain", "Do you feel any pain in general?" },
    
    { S_NOT_HEALING_PROPERLY, "Not healing properly", "Is nothing healing properly?" },

    { S_NITS, "Nits", "Do you have little white eggs in your hair (nits)?" },

    { S_NAUSEA, "Nausea", "Do you experience nausea?" },

    { S_DIZZINESS, "Dizziness", "Do you find yourself to be very dizzy?" },

    { S_DIAPER_RASH, "Diaper rash", "Does your baby have a diaper rash (if you have a baby)?" },

    { S_IRRITATION_OF_THE_EYE, "Irritation of the eye", "Are your eyes getting irritated?" },

    { S_BLOOD_IN_COUGH, "Blood in cough", "Do you cough out blood?" },

    { S_BLEEDING_GUMS_AFTER_BRUSHING, "Bleeding gums after brushing", "Do your gums bleed after brushing?" },

    { S_BAD_SMELL, "Bad smell", "Does your tattoo have a bad smell (if you have one)?" },

    { S_BODY_ACHES, "Body aches", "Does your body ache?" },

    { S_FEVER, "Fever", "Have you had a fever recently?" },

    { S_DEHYDRATION, "Dehydration", "Do you find yourself dehydrated a lot?" },

    { S_BRIGHT_RED_THROAT, "Bright red throat", "Is the colour of your throat bright red?" },

    { S_LOSS_OF_HEIGHT, "Loss of height", "Does it seem like you are getting shorter?" },

    { S_INSTANT_SHARP_BURNING_PAIN, "Instant, sharp, burning pain", "Did you feel a sharp, burning sensation?" },

    { S_HEAVY_BLEEDING_DURING_PERIODS, "Heavy bleeding during periods", "Do you experience heavy bleeding during periods (for girls only of course)?" },

    { S_LOSS_OF_BREATH, "Loss of breath", "Are you short of breath lately?" },

    { S_HEADACHE, "Headache", "Do you experience many headaches?" },

    { S_LOSS_OF_APPETITE, "Loss of appetite", "Have you not felt like eating recently?" },

    { S_BAD_POSTURE, "Bad posture", "Do you have a bad posture?" },

    { S_BLISTERS, "Blisters", "Do you get many blisters?" },

    { S_CHILLS, "Chills", "Do you sometimes get chills?" },

    { S_ITCHY_EYE_OR_DISCOMFORT_OR_PAIN, "Itchy eye or discomfort/pain", "Do you feel pain from your eye, discomfort, or itchiness?" },

    { S_DROOLING, "Drooling", "Do you drool more than usual?" },

    { S_ITCHINESS, "Itchiness", "Do you experience any itchiness throughout your body?" },

    { S_INDENTATION_OF_THE_TATTOO, "Indentation of the tattoo", "Do you have an indentation of your tattoo (if you have one)?" },

    { S_FATIGUE, "Fatigue", "Do you suffer from fatigue?" },

    { S_BAD_BREATH_OR_TASTE_IN_MOUTH, "Bad breath or bad taste in the mouth", "Does your mouth smell or taste bad?" },

    { S_DIARRHEA, "Diarrhea", "Have you had diarrhea?" },

    { S_PALENESS, "Paleness", "Do you seem pale?" },

    { S_LABORED_BREATHING, "Labored breathing", "Do you have trouble breathing?" },

    { S_VOMITING, "Vomiting", "Have you vomited?" },

    { S_SNEEZING, "Sneezing", "Have you been sneezing a lot recently?" },

    { S_WHEEZING, "Wheezing", "Do you wheeze often?" },

    { S_TOOTH_DECAY, "Tooth decay", "Are your teeth starting to decay?" },

    { S_RUNNY_NOSE, "Runny nose", "Do you have a runny nose?" },

    { S_RASH, "Rash", "Do you have a rash?" },

    { S_SWELLING, "Swelling", "Is any part of your body swollen?" },

    { S_SORE_THROAT, "Sore throat", "Do you have a sore throat?" },

    { S_MUSCLE_ACHES, "Muscle aches", "Do your muscles ache?" },

    { S_STUFFY_NOSE, "Stuffy nose", "Do you have a stuffy nose?" },

    { S_RECEDING_GUMS, "Receding gums", "Are your gums starting to recede?" },

    { S_PUS_OR_DRAINAGE, "Pus or drainage", "Do you experience any pus or drainage?" },

    { S_RED_BUMPS, "Red bumps", "Are you starting to get red bumps?" },

    { S_RED_AREAS, "Red areas", "Do you see any red areas on your body?" },

    { S_RED_HAZE, "Red haze", "Do you see a red haze on your body?" },

    { S_SINUS_PRESSURE, "Sinus pressure", "Is there pressure inside your sinus?" },

    { S_SENSITIVITY_TO_LIGHTS_NOISE_OR_ODOURS, "Sensitivity to lights, noise, or odours", "Are you sensitive to lights, noise, or odours?" },

    { S_DEEP_POCKETS_BETWEEN_TEETH_AND_GUMS, "Deep pockets between teeth and gums", "Are there deep pockets between your teeth and gums?" },

    { S_BACK_PAIN, "Back pain", "Does you back hurt?" },

    { S_THICK_YELLOW_FLUID_COMING_FROM_EARS, "Thick, yellow fluid coming from ears", "Do you see thick, yellow fluid coming from your ears?" },

    { S_FLUSHED_CHEEKS, "Flushed cheeks", "Are your cheeks flushed?" },

    { S_TENDENCY_TO_CHEW_ON_HANDS, "Tendency to chew on hands", "Do you have a tendency to chew your hands more than usual?" },

    { S_PAIN_FROM_TEETH, "Pain from teeth", "Do your teeth hurt?" }    
};

disease g__disease[] = 
{
    { D_NONE, "No Disease", { S_NONE }, 0, 0, "No treatment is needed." },

    { D_HEARTBURN, "Heart Burn", { S_CHEST_DISCOMFORT_OR_PAIN, S_SORE_THROAT, S_THROAT_PAIN, S_COUGH }, 3, 2, "Heartburn can be very painful so I have compiled some tips to ease the pain.:\nOne often used natural heartburn rememdy is calcium.\nIt's also an adctive ingredient in many over-the-counter antacids.\nMost of the research for heartburns is centered around a product called Iberogast.\nIt's made out of 9 different herbs:\n Angelica, Caraway, Clown'smustard plant, German chamomile, Greater celadine, Lemon balm, Licorice, Milk thistle, and Peppermint.\nStudies have shown that Iberogast decreases heartburn, cramping, nausea, and stomach pain.\n However, if you have Gastroesophageal reflux disease, it's a good idea not to take peppermint oil." },

    { D_MEASLES, "Measles", { S_SORE_THROAT, S_THROAT_PAIN, S_FEVER, S_IRRITATION_OF_THE_EYE, S_SWELLING, S_DIARRHEA, S_ITCHINESS, S_FATIGUE, S_SNEEZING, S_RUNNY_NOSE }, 7, 4, "Measles can be extremely harmful if not dealt with, so remember to call a doctor, but in the meantime, here are ways to cure it: \nIt's okay to take medicine to lower the fever. \nIf you have measles, you should stay away from public places as much as possible. \nIf a child has it, they are more likely to use Vitamin A supplements. \nIf you have been exposed to it, you might be able to recieve the vaccination before the infection begins. \nMake sure to get a shot of immunoglobulin (IG) right away." },

    { D_GINGIVITIS, "Gingivitis", { S_BLEEDING_GUMS_AFTER_BRUSHING, S_CHANGE_IN_JAW_ALIGNMENT, S_DEEP_POCKETS_BETWEEN_TEETH_AND_GUMS, S_RECEDING_GUMS, S_BAD_BREATH_OR_TASTE_IN_MOUTH, S_RED_AREAS  }, 4, 2, "Gingivitis is very dangerous and should be controlled, here are ways to do that:\nBrush your teeth at least twice a day for 2 min and floss everyday.\nUse an antibacterial mouth rinse for protection against plaque and to improve gingivitis.\nIf you already have gingivitis, your dentist can scrape plaque build up at the gum line." },

    { D_A_BEE_STING, "A bee sting", { S_INSTANT_SHARP_BURNING_PAIN, S_PAIN_AROUND_STING, S_SWELLING, S_RED_AREAS, }, 3, 2, "Bee stings are a different illness because you won't need much depending on your allergies and the severity. If you are not allergic to bees, not much medical attention is required except for this:\nRemove any stingers remaining in the skin immediately. Some people scrape out the stinger using a credit card.\nYou should apply ice to the sting site which might provide mild relief.\nConsider taking an antihistamine such as dphenhydramine (Benadryl) or a nonsedating one such as loratadine (Claritin) for itching.\nYou may also want to take pain relievers.\nWash the sting site with soap and water and then place an antibiotic ointment on the sting site.\nIf its been more than 10 years since you had your tetanus booster immunization, get a booster within the next couple of days.\nOther then that, there is not really any immediate care other then removing the stinger and waching the area./nHowever, if you are allergic, you SHOULD seek medical attention right away, inject Epinephrine immdeiately, have someone perform CPR on you if you stop breathing, and then make sure someone stays with you in case of another attack!" },

    { D_MONONUCLEOSIS, "Mononucleosis", { S_SPOTS_OR_COATING_ON_THROAT_AND_TONSILS, S_ABDOMINAL_PAIN_AND_CRAMPS, S_CHILLS, S_BODY_ACHES, S_FEVER, S_HEADACHE, S_FATIGUE, S_RASH, S_SORE_THROAT, S_RED_AREAS }, 4, 3, "Self care is really all that is needed for treating this disease.\nHere are steps you can take to relieve symptoms until you are back to normal.\n\n1) Don't push yourself if you have mononucleosis, if you are tired, it's crucial to rest and let your body have some time to heal.\n\n2) Avoid sports and heavy lifting for about 4 weeks after you are ill with mononucleosis to reduce the risk of rupturing or injuring your spleen.\n\n3) Take acetaminophen (like Tylenol) or ibuprofen (like Advil) to decrease your fever and to relieve sore throat and headache.\n\n4) Relieve your throat with cool liquids and saltwater gargles. hard candies or throat lozenges work too!\n\n5) Drink lots of fluids to prevent dehydration." },

    { D_OSTEOPOROSIS, "Osteoporosis", { S_BROKEN_BONES_OR_FRACTURES, S_LOSS_OF_HEIGHT, S_BAD_POSTURE, S_BACK_PAIN }, 3, 1, "For osteoporosis, calcium and vitamin D are essential to bone health.\nExcersize is also very important to strengthening bone mass.\nSome medications are Actonel, Binsto, Boniva, and Fosamax.\nThey basically inhibit cells that break down bone and slowing bone loss.\nThere is another medicine called Reclast and is given once a year for a 15 minute infusion in a vein.\nIt's supposed to increase bone strength and decrease fractures.\nForteo is another type of medication and is used in postmenopausal women and men who have a very high risk for a fracture.\nIt was the 1st drug to stimulate new bone formation and increase bone mineral density.\nProlia can also be preformed, it's basically a human, lab produced antibody that inactivates the body's nobe breakdown mechanism.\nTo prevent Osteoporosis, eat high calcium foods such as dairy products, green vegetables, sardines/salmon with bones, and tofu.\nVitamin D is also very important and all you really need to do is just go outside and expose your skin to sunlight. Yet, there are some food items such as fish, fish liver oils, beef liver, cheese, egg yolks, fortified breackfast cereals, juices, milk products, yogurt, and margarine." },

    { D_ANEMIA, "Anemia", { S_GRUMPY_OR_CRANKY, S_TROUBLE_CONCENTRATING, S_PALENESS, S_DIZZINESS, S_LOSS_OF_BREATH, S_HEADACHE, S_FATIGUE }, 4, 2, "Here are ways to fight Anemia: \nIf you have iron deficiency anemia, try taking iron supplement pills and getting lots of iron in your food everyday such as meats, vegetables, and whole grains. \nTry taking vitamin C (absorbic acid) or drink some orange juice with your pills. \nIt also helps to steam vegetables to maintain their iron content. \nDO NOT take iron pills within 2 hours of antacids, tetracycline (an antibiotic), tea, coffee, chocolate, or other products high in caffeine." },

    { D_MIGRAINE, "Migraine", { S_SENSITIVITY_TO_LIGHTS_NOISE_OR_ODOURS, S_HEAD_PAIN, S_NAUSEA, S_DIZZINESS, S_LOSS_OF_APPETITE, S_ITCHY_EYE_OR_DISCOMFORT_OR_PAIN, S_PALENESS, S_VOMITING }, 4, 2, "Migrains usually can't be cured until you find the cause of it, but here are ways to reduce the pain: \n Take pain relievers such as aspirin, Aleve, Tylenol, or Advil. \nWARNING, taking too much causes new more difficult to treat headaches called rebound or pain reliever-induced headaches. \nThere are some drugs called Triptans which have been used often for migraines. \nThe drugs include, Amerge, Imitrex, Maxalt, Zecuity, Zomig, etc. \nThese drugs come in pills, injections, and skin patches." },

    { D_UTERINE_FIBROIDS, "Uterine Fibroids", { S_PAIN_IN_BELLY_OR_PELVIS, S_HEAVY_BLEEDING_DURING_PERIODS, S_BLOATING, S_CONSTIPATION }, 3, 2, "Fibroids can be removed using surgery.\nFor surgery The blood supply to fibroids can be cut off, the whole uterus can be removed from your body, or medicine can shrink fibroids for sometime.\nIt all depends on the severity of your symptoms and if you want to keep your fertility.\nHere are some medicines that are used to relieve heavy menstrual bleeding, anemia, or painful periods:\nNonsteroidal anti-inflammatory drug therapy, birth control hormones that come in a form of a pill, patch or ring, An intrauterine device, A progestin shot, or Iron suppplements.\nTo shrink a fibroid, you may be recommened uterine fibroid embolization whichi basically blocks the blood supply to the fibroid making it shrink.\nAlthough this treatment may not be necessary, Hysterectomy is the only treatment that ensures a cure from fibroids.\nSome home remedies are lying down and placing a hot pack or hot water bottle on your lower abdomen to relive the pain.\nMedicines like Advil and Motrin can also relive pain." },

    { D_PINK_EYE, "Pink Eye", { S_IRRITATION_OF_THE_EYE, S_ITCHINESS, S_ITCHY_EYE_OR_DISCOMFORT_OR_PAIN, S_SWELLING, S_RED_AREAS }, 4, 2, "Pink Eye is serious and contagious so you should schedule an appointment with the doctor right away if it gets serious! \nBut for home rememdies, here are some tips to help cure it: \nIf you wear contacts, remove it, wash it thoroughly, and wear glasses until it disappears. \nCold compresses should generally be used if an allergy is the problem, but if it's an infection, warm compresses will most likely do the trick. \nUse a different compress for each eye, and use a clean compress for each application. \nWhen cleaning your eye, wipe from the inside (next to the nose) toward the outside. \nRemember to use a clean surface for each wipe so that the drainage being cleaned away is not rubbed back on the eye. \n If washcloths are used to clean the eye, put them in the laundry right away so that no one else picks them up or uses them. \nPrescription antibiotic treatment usually kills the bacteria that cause pinkeye. \nMedicine may include eye drops and eye ointment." },

    { D_CHICKEN_POX, "Chicken Pox", { S_RED_AREAS, S_BLISTERS, S_ITCHINESS, S_FEVER, S_HEADACHE, S_LOSS_OF_APPETITE, S_FATIGUE }, 4, 3, "Follow these steps to get better: \n\n1) Use cool wet compresses or give baths in cool or lukewarm water every 3 to 4 hours for the first few days. Oatmeal bath products, available at supermarkets and drugstores, can help to relieve itching. (Baths do not spread the rash.) \n\n2) Pat your body dry. \n\n3) Put calamine lotion on itchy areas (but don't use it on the face, especially near the eyes) \n\n4) Eat foods that are cold, soft, and bland because chickenpox in the mouth can make drinking or eating difficult. \n\n5) Ask pharmacists about pain-relieving creams to apply to sores in the genital area. \n\n6) Take acetaminophen regularly to help reduce pain if you have mouth blisters." },

    { D_INFECTED_TATTOO, "Infected Tattoo", { S_PAIN_AROUND_TATTOO, S_INDENTATION_OF_THE_TATTOO, S_NOT_HEALING_PROPERLY, S_BAD_SMELL, S_PUS_OR_DRAINAGE, S_RED_HAZE }, 4, 1, "Tattoos are cool (of course I can't have one because I am a machine...), but an infection is not. So here are ways to treat an infected tattoo:\nStop an bleeding by applying pressure to the wound. Its perfectly normal for the tattoo site to ooze small amounts of blood for upto 24 hrs and clear, yellow, or blood-tinged fluid for several days.\nThen, apply a cold pack to reduce the swelling, bruising, or itching.\nNEVER place ice right to the skin. This can cause tissue damage. Just remember to place a layer of fabric between the cold pack and the skin.\nTake an antihistamine like Benadryl or Chlor-Trimenton to treat hives and itching.\nProtect your tattoo with a bandage if it might become dirty or irriated.\nApply an antibiotic ointment such as Polysporin or Bacitracin to a non-stick bandage such as Telfa.\nApply the bandage on the tattoo.\nPlace a clean bandage once a day and change the the bandage if it gets wet.\nIf the bandage sticks, soak the area around the tattoo in warm water for a couple of minutes or take the bandage off under running water in the shower." },

    { D_EAR_INFECTION, "Ear Infection", {  S_THICK_YELLOW_FLUID_COMING_FROM_EARS, S_PAIN_AROUND_EAR, S_FEVER, S_LOSS_OF_APPETITE }, 3, 1, "To cure your ear infection, follow this advice: \nUse pain relievers. \nPain relievers such as nonsteroidal anti-inflammatory medicines (Advil, Aleve, and Motrin) and acetaminophen (such as Tylenol) will make you feel better. Giving you this medication to relieve pain before you go to bed is especially important. \nAlways remember to follow all instructions on the label. \nDO NOT take aspirin if you are younger than 20, because you may be vulnerable to Reye syndrome, a serious illness. \nApply heat to the ear, which may help with pain. \nUse a warm washcloth or a heating pad. \nMake sure to get plenty of sleep. \nSleep will help the body fight the ear infection. \nAlso, use ear drops. \nDoctors will often suggest eardrops for earache pain. \nDon't use ear drops without a doctor's advice, especially if you have tubes in your ears. \nIf you are not better after a few days of these remedies, call a doctor immediately." },

    { D_NASAL_CONGESTION, "Nasal Congestion", { S_SINUS_PRESSURE, S_POST_NASAL_DRIP, S_ITCHY_EYE_OR_DISCOMFORT_OR_PAIN, S_SNEEZING, S_STUFFY_NOSE }, 4, 2, "Nasal Congestion can be annoying, so here are remedies to cure it: \nTake long showers or breathe in steam from a pot on the stove. (Don’t burn yourself!) \nDrink lots of fluids, which will thin out your mucus which might help prevent your sinuses from getting blocked up. \nIt's also helpful to use a nasal saline spray which is simple unmedicated salt water to help prevent your nasal passages from drying out. \nYou should also irrigate. \nIt may seem odd, but this technique of flushing out nasal passages with salt water has some good scientific evidence behind it. \n The water washes out mucus and other debris, including allergens or germs, while keeping your nasal passages moist. \nFor this treatment, there are many different approaches. \nYou could just use a syringe, a neti pot, or one of the more elaborate and expensive nasal irrigators available in stores. \nUse sterile or previously boiled water to make up the irrigation solution. \nIt’s also important to rinse the irrigation device after each use and leave open to air dry. \nAlso, use warm compresses on your face. \nSitting with a warm, wet towel on your face may relieve discomfort and open your nasal passages. \nAt night, lie on a couple of pillows. \nKeeping your head elevated makes breathing more comfortable and easier. \nAvoid chlorinated pools. \nAlthough people think moisture will help, the chlorine in pools can irritate the mucous membranes in your nasal passages. \nIf it helps, use a humidifier or vaporizer." },

    { D_CHEST_CONGESTION, "Chest Congestion", { S_BLOOD_IN_COUGH, S_LOUD_NOISES_WHILE_BREATHING, S_CHEST_DISCOMFORT_OR_PAIN, S_COUGH, S_DIZZINESS,  S_LOSS_OF_BREATH, S_LABORED_BREATHING, S_WHEEZING, S_RUNNY_NOSE }, 5, 2, "Steam treatment is one of the best chest congestion remedies. \nAll you need is some very hot water in a bowl and mix some drops of any essential oil from among eucalyptus, clary sage, pine and rosemary. Eucalyptus oil and leaves are an effective remedy. Now put your face over the bowl in such a way that steam can enter your nostrils and cover the head with a towel big enough to cover the bowl. Inhale the steam for a few seconds or minutes that is tolerable. Inhaling steam loosens up the hardened phlegm to be easily coughed up giving relief. \nSpicy foods that contain chili, garlic and ginger paste act as decongestants. \nHot foods kill bacteria and eating spicy foods can help in getting rid of the unwanted bacteria. \nTea prepared with herbs, especially ginger, is very beneficial in getting relief from chest congestion. \nGinger is a great anti-inflammatory agent that can be chewed raw with some salt for getting fast relief. \n Tea brewed with a few drops of chamomile can also help relieve congestion. \nAlso, drink hot water every time you feel thirsty and in the morning just after waking up when the mucous is most thick and hardened in the chest. It will help in dissolving the phlegm and will make it easier to cough up. \nGargle with hot salty water three to four times a day to loosen up the phlegm." },

    { D_ATHLETE_FOOT, "Athlete's Foot", { S_PEELING_OR_CRACKING_OR_SCALING_OF_FOOT, S_BLISTERS, S_ITCHINESS, S_RED_AREAS }, 3, 1, "No, this is not a disease only athletes get, it's a disease that can impact anyone so here are ways to cure it: \nMost cases of athlete's foot are treated at home using an antifungal medicine to get rid of the fungus, or reduce the growth. \nNonprescription antifungals usually are used first. \nThese also include clotrimazole (Lotrimin), miconazole(Micatin), terbinafine (Lamisil), and tolnaftate (Tinactin). \nNonprescription antifungals are applied to the skin (topical medicines). \nFor a severe infection, presciption antifungals can be used. \nHowever, for a severe case of athlete's foot, you may get prescribed oral antifungal medicine pills. \nWARNING, they are only used for extreme cases because they are expensive and require periodic testing for harmful side effects. \nEven if it seems like your symptoms improve, remember to finish the full course of the medicine because Athlete's foot can return after anitfungal pill treatment. \nReinfection is common, and athlete's foot should be fully treated each time symptoms develop." },

    { D_WISDOM_TEETH, "Wisdom Teeth", { S_CROWDING_OF_OTHER_TEETH, S_CHANGE_IN_JAW_ALIGNMENT, S_TOOTH_DECAY, S_SWELLING, S_PAIN_FROM_TEETH }, 4, 2, "Some dentists think it is better to wait and remove a wisdom teeth only if there is a problem specifically if you are over 30.\nBasically, wisdom teeth that are causing many problems should most likely be removed. An oral or maxillofacial surgeon or a dentist can extract your wisdom teeth.\nYou should typically schedule an appointment with a dentist is your wisdom teeth are causing many problems, but in the meantime, there are some rememdies you can do to reduce pain or swelling:\nPlace an ice pack on the oustide of your cheek for 20 minutes, then remove it. (You can repeat if necessary).\nGently rinse your mouth with warm salt water every 2-3 hourse.\nYou can also use over-the-counter medicines to relieve face or jaw pain such as Acetaminophen (Tylenol), ibuprofen (Advil or Motrin), Naproxen (Aleve or Naporsyn), or aspirin (such as Bayer or Bufferin).\nDO NOT use heat or place an aspirin directly on your gums because if used in this way, aspirin can damage your gums." },

    { D_BRONCHITIS, "Bronchitis", { S_CHEST_DISCOMFORT_OR_PAIN, S_COUGH, S_FEVER, S_FATIGUE, S_WHEEZING }, 3, 2, "Here are tips to get rid of bronchitis: \nFor acute bronchitis, all you really need is lots of rest, lots of liquids, avoid smoking and fumes, and maybe obtain a prescription for inhaled bronchodilator and/or cough syrup. \nFor chronic bronchitis, oral steroids are used to reduce inflammation and/or supplementary oxygen. \nWith chronic bronchitis, your lungs are open for infections. \nUnless a doctor advises against it, get a flu shot every year and a vaccination for pneumonia. \nFor healthy people, antibiotics don't have to be used. \nCoughing is your body's way of getting rid of excess mucus. \nHowever, if it becomes disruptive, painful, or keeps you from sleeping, then you may get prescribed a cough suppressant." },

    { D_INGROWN_TOENAIL, "Ingrown Toenail", { S_SWELLING, S_PUS_OR_DRAINAGE, S_RED_AREAS }, 3, 2, "There are lots of things you can do to reduce swelling and relieve tenderness such as:\nSoak your feet in warm water for 15-20 mins 3-4 times a day.\nYou can also place cotton or dental floss under your toenail after each soaking.\nNext, apply anibiotic cream and then bandage your toe.\nConsider wearning open-toes shoes or sandals until your toe feels better.\nTake pain relievers such as Tylenol, Advil, Motrin IB, Aleve,etc to reduce toe pain." },

    { D_ECZEMA, "Eczema", { S_THICKENING_OF_THE_SKIN, S_ITCHINESS, S_RASH }, 3, 2, "Great skin care is an important part to controlling eczema.\nFor people with mild eczema, changing their skin care routine and making healthier lifestyle choices may be all that is needed to treat eczema.\nFor severe cases of eczema, here are some non-drug treatments:\nMild soap and moisturizer helps. Gentle soaps such as Sydnets, are available at most drug stores. A good moisturizer helps maintain the skin's natural moisture. Some people will add a very small amount of bleach to their bath water. It's known to kill bateria that live on the skin.\nTaking short, warm showers are much better for people with eczema than long, hot showers as this will dry out the skin.\nReducing stress by getting excersize and taking time to relax helps as well.\nSome other medications for ezcema include:\nHydrocortisone, Antihistamines, Corticosteroids, Ultraviolet light therapy, Immunosuppressants, Immunomodulators, and Prescription-strength moisturizers." },

    { D_ASTHMA, "Asthma", { S_CHEST_DISCOMFORT_OR_PAIN, S_LOSS_OF_BREATH, S_WHEEZING, S_COUGH }, 3, 2, "Asthma is a very broad disease as it can go away in a couple of weeks, or years. You can still live a happy, healthy life with asthma if you take the right medication.\nMost people with asthma take these basic types of drugs:\nSteroids/Other Anti-Inflammatory Drugs and Broncholidators, Asthma inhalers, and Asthma Nebulizer. All of these will help reduce the effects of asthma. WARNING: IF YOU EXPERIENCE AN ASTHMA ATTACK, CALL A DOCTOR IMMEDIATELY! To look at more info on asthma, you can visit WebMD's article on Asthma." },

    { D_TEETHING_IN_BABIES, "Teething", { S_DIAPER_RASH, S_FEVER, S_DROOLING, S_DIARRHEA, S_RUNNY_NOSE }, 4, 2, "If your baby has discomfort while teething, you can do these things:\n\n1) Rub the affected gum. Use a clean finger (or cold teething ring) to gently rub the area of tooth eurption for only 2 minutes at a time. Most babies usually find this soothing, although they may resist at first.\n\n2) Keep safe objects for babies to chew on, such as teething rings. Babies who are teething tend to like to chew on things to reduce the pressure from an erupting tooth.\n\n3) Give your baby an over-the-counter pain relief medicine that is meant for their particular age. Medicine such as acetaminophen or ibuprofen will help reduce your baby's discomfort." },

    { D_STREP_THROAT, "Strep Throat", { S_SPOTS_OR_COATING_ON_THROAT_AND_TONSILS, S_SWOLLEN_LYMPH_NODES, S_BLOOD_IN_COUGH, S_COUGH, S_BRIGHT_RED_THROAT, S_SORE_THROAT }, 3, 2, "Strep Throat can be a pain, so here are ways to cure this disease:\nMake sure to drink lots of fluids and increase humidity (moisture in the air) in your home to keep your throat moist.\nHerbal teas might help relieve pain from the symptoms.\nAlso, get lots of rest. Stay home and sleep on the 1st day of antibiotic treatment. You are contagious and may pass the infection to other people.\nTake nonprescription medicines to relieve a painful sore throat and fever.\nIt helps incredibly to avoid sneezing or coughing on others, washing your hand often, using tissues that are disposable, not hankerchiefs, use a new toothbrush when you are sick and then replacing it when you are well." },

    { D_INFECTED_PIERCING, "Infected Piercing", { S_PAIN_AROUND_PIERCING, S_NOT_HEALING_PROPERLY, S_PUS_OR_DRAINAGE, S_SWELLING }, 3, 1, "There really is no specific verified treatment. You might want to consult a doctor or the person who did your piercing about treating a piercing infection." },

    { D_FLU, "Flu", { S_CHEST_DISCOMFORT_OR_PAIN, S_COUGH, S_POST_NASAL_DRIP, S_PAIN, S_NAUSEA, S_BODY_ACHES, S_FEVER, S_HEADACHE, S_LOSS_OF_APPETITE, S_ITCHY_EYE_OR_DISCOMFORT_OR_PAIN, S_FATIGUE, S_DIARRHEA, S_VOMITING, S_SNEEZING, S_SORE_THROAT, S_MUSCLE_ACHES, S_STUFFY_NOSE }, 11, 3, "Everyone gets the flu in their life, so it's important to know what to do about it when the time comes, here are facts to get rid of the flu: \nThe treatments all depend on what your symptoms are, if you have nasal or sinus congestion, decongestants are what you should take. \nIf you had a runny nose, post nasal drip, itchy or watery eyes, then an antihistamine would be helpful to use. \nRemember that both decongestants and antihistamines can interact with other medication you may be taking and may aggravate some conditions. \nKeep in mind that over-the-counter usually make people feel drowsy, whereas decongestants often make people hyper or awake. \nFor a persistent cough, you'll find many cough medicines on a pharmacy shelf with many combinations such as decongestants, antihistamines, analgesics/antipyretics, cough suppressants, and expectorants. \nIf you don't want to use much medication, there are home rememdies to cure the flu: \n\n1) Breathe aromatic steam. \nTry adding a few drops of eucalyptus oil or menthol to water. Eucalyptus opens up bronchial tubes to ease congestion and make breathe a whole lot easier. \n\n2) Take a warm shower. \nTaking a warm shower and closing your bathroom door works as your own sauna. \nThe steam from the bathroom helps open your airways and moisten the mucus in your sinuses. \n\n3) Stay hydrated and drink at least 8 cups of water each day. Water maintains hydration in your respiratory system. \nHot liquids tend to reduce upper respiratory infections. \nAvoid coffee, tea with caffeine, or alcoholic beverages. \n\n4)Use moist heat compresses. \nIf your head is hurting and it's hard to breathe through your nose, you may relieve this by applying warm moist compresses to the cheeks & sinuses." },

    { D_STOMACH_FLU, "Stomach Flu", { S_ABDOMINAL_PAIN_AND_CRAMPS, S_FEVER, S_DEHYDRATION, S_PAIN, S_VOMITING }, 4, 3, "Sorry, there is no real verified medication, but all you really have to do is follow the treatments for a normal flu disease." },

    { D_FOOD_POISONING, "Food Poisoning", { S_ABDOMINAL_PAIN_AND_CRAMPS, S_NAUSEA, S_FEVER, S_LOSS_OF_APPETITE, S_DIARRHEA, S_VOMITING }, 4, 3, "Food Poisoning is not fun... so I have made a list of how to control food poisoning:\n\n1) Controlling nausea and vomiting. Avoid solid foods and eat light, bland foods like saltine crackers, bananas, rice, or bred. Sipping a little bit of soda helps to prevent vomiting. Don't eat fried, greasy, spicy, or sweet foods until you have stopped vomiting.\n\n2 Preventing Dehydration. Drink clear fluids, usually starting at very small sips and gradually drinking more. If vomiting and diarrhea last more than 24 hrs, drink an oral rehydration solution.\n\n3) When to call a docotor. There are times where you will have to call a doctor and these are those times:\nWhen you show signs of severe dehydration such as dry mouth, reduced urination, dizziness, fatigue, or higher heart or breathing rate,\nWhen diarrhea lasts for more than 3 days,\nWhen diarrhea happens after you consume seafood, or mushrooms,\nWhen diarrhea is accompanied with a fever,\nWhen you have blood or dark stools,\nor when you have diarrhea with prolonged vomiting that prevents keeping liquids down." },

    { D_HEAD_LICE, "Head Lice", { S_NITS, S_ITCHINESS, S_RED_BUMPS }, 2, 1, "Here are some tips to get rid of lice: \nYou can obtain a recommended medicated shampoo, cream rinse, or lotion to kill the lice. \nIt may be over-the-counter (OTC) or prescription medications. \nMedicated lice treatments usually kill the lice and nits, but it may take a few days for the itching to cease. \nFor very resistant lice, an oral medication may need to be used. \nIt's crucial to follow the directions exactly because these products are insecticides. \nApplying too much medication, or using it many times may increase the risk of harm. \nAlways follow directions on the product label to ensure that the treatment works properly. \nAfter treatment, your doctor may suggest combing out the nits with a fine-tooth comb and also may recommend repeating treatment in 7 to 10 days to kill any newly hatched nits. \nAfter rinsing the product from the hair and scalp, use a fine-toothed comb or special “nit comb” to remove dead lice and nits.\nAnother way to treat head lice is by adding 5 drops of Tea Tree Oil to 1oz of shampoo.\nRub it in wet hair and then leave it for about 10 min.\nThen rinse your hair and repeat this daily until all lice and eggs are gone." },

};
// -----------------------------------------------------------------------------
