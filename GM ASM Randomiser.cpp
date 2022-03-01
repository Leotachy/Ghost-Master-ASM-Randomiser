
#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <ctime>
#include <sstream>

using namespace std;



void GetRandomiserParameters            (bool *RandomiserParameters);
string GetValidModsPath                 (bool RandHaunters);
int GetHaunterData                      (string ModsPath, string* HaunterScriptInstanceArray, string* HaunterEnumArray, string* StockHaunterArray, int* HasManifestPowerBaseKitArray, int* HaunterIDArray, string* HaunterFetterFlagStringArray);
void OutputStockHaunters                (string ModsPath, string fileName, int* StockHaunterIDArray, int StockHaunterCount);
void OutputActGifts                     (string ModsPath, string fileName, string* HaunterEnumArray, int Act2GiftCount, int Act3GiftCount, int Act4GiftCount, int* StockHaunterAndActGiftIDArray);
bool DeleteAndRename                    (string ModsPath, string fileName);
void GetActGiftsForEachAct              (string ModsPath, string fileName, int& Act2GiftCount, int& Act3GiftCount, int& Act4GiftCount);
void OutputRandomiserInfo               (string ModsPath, string app_version, unsigned seed, bool RandHaunters, bool RandScOrd, bool PrevImpSav, bool DialogueFix, bool RandomDialogue);

void OutputScenarioOrder                (string ModsPath, string app_version, string* Sc_Available_Array, string* Sc_Completed_Array, string* Sc_Name_Array, string* Sc_ScriptInstance_Array, int* ScenarioIndexes);
void GetRandomScenarioOrder             (bool PreventImpSaves, int ScenarioIndexes[], unsigned seed);

void GetSpecialHaunters                 (int* HasManifestPowerBaseKitArray, unsigned seed, int HaunterCount, int* SpecialHaunters, int* HaunterIDArray, string* HaunterFetterFlagStringArray, int* RemainingRestlessSpiritsIDArray);
void SubtractActGifts                   (int* StockHaunterAndActGiftIDArray, int* StockHaunterArray, int ActGiftCount, int StockHaunterCount);
int GetStockHaunterCount                (int HaunterCount, string* StockHaunterArray);
int GetCountOfOtherHauntersAndSubtractRestlessSpirits   (int HaunterCount, int* HaunterIDArray, int* RestlessSpiritIDArray, int* StockHaunterAndActGiftIDArray);

int GetDialogueHashesAndCountASM        (string ModsPath, string DialogueHash_arr[]);
string GetPathToEnglishVdTxt            (string ModsPath);
int GetDialogueHashesTXTAndCount(string NewPath, string* vdDialogueHash_arr, string* SpeechName, unsigned seed);
void ClearSoundSubtitles                (string* DialogueHash_arr, string* vdDialogueHash_arr, int vdDialogueCount, int DialogueCount);
int OutputSoundSubtitles                (string ModsPath, string* DialogueHash_arr, int DialogueCount);
void OutputNarratorSpeechHashes(string ModsPath, string* SpeechName, string app_version);

void RandomiseHaunterDialogue           (string* DialogueHash_arr, int DialogueCount, string* vdDialogueHash_arr, int vdDialogueCount, unsigned seed);

string string_to_hex                    (const string& input);



unsigned int __cdecl crc32bin           (const char* byte, int ArrayLenght);
unsigned int __cdecl crc32              (const char* String);


void RandScenario_Haunting101   (string ModsPath, string app_version, string* HaunterEnumArray, string* HaunterScriptInstanceArray, int* RestlessSpiritIDArray);
void RandScenario_WeirdSeance   (string ModsPath, string app_version, string* HaunterEnumArray, string* HaunterScriptInstanceArray, int* RestlessSpiritIDArray);
void RandScenario_Calamityville (string ModsPath, string app_version, string* HaunterEnumArray, string* HaunterScriptInstanceArray, int* RestlessSpiritIDArray);
void RandScenario_Summoners     (string ModsPath, string app_version, string* HaunterEnumArray, string* HaunterScriptInstanceArray, int* RestlessSpiritIDArray, int* SpecialHaunters);
void RandScenario_Deadfellas    (string ModsPath, string app_version, string* HaunterEnumArray, string* HaunterScriptInstanceArray, int* RestlessSpiritIDArray);
void RandScenario_Unusual       (string ModsPath, string app_version, string* HaunterEnumArray, string* HaunterScriptInstanceArray, int* RestlessSpiritIDArray);
void RandScenario_Poultrygeist  (string ModsPath, string app_version, string* HaunterEnumArray, string* HaunterScriptInstanceArray, int* RestlessSpiritIDArray, int* SpecialHaunters);
void RandScenario_Facepacks     (string ModsPath, string app_version, string* HaunterEnumArray, string* HaunterScriptInstanceArray, int* RestlessSpiritIDArray, int* SpecialHaunters);
void RandScenario_Phantom       (string ModsPath, string app_version, string* HaunterEnumArray, string* HaunterScriptInstanceArray, int* RestlessSpiritIDArray, int* SpecialHaunters);
void RandScenario_Wisp          (string ModsPath, string app_version, string* HaunterEnumArray, string* HaunterScriptInstanceArray, int* RestlessSpiritIDArray, int* SpecialHaunters);
void RandScenario_Spooky        (string ModsPath, string app_version, string* HaunterEnumArray, string* HaunterScriptInstanceArray, int* RestlessSpiritIDArray, int* SpecialHaunters);
void RandScenario_Ghostbreakers (string ModsPath, string app_version, string* HaunterEnumArray, string* HaunterScriptInstanceArray, int* RestlessSpiritIDArray);
void RandScenario_MortalJacket  (string ModsPath, string app_version, string* HaunterEnumArray, string* HaunterScriptInstanceArray, int* RestlessSpiritIDArray);
void RandScenario_Cuckoos       (string ModsPath, string app_version, string* HaunterEnumArray, string* HaunterScriptInstanceArray, int* RestlessSpiritIDArray);

unsigned int crc_table[256] = { 0x00000000, 0x4C11DB7, 0x9823B6E, 0xD4326D9, 0x130476DC, 0x17C56B6B, 0x1A864DB2, 0x1E475005, 0x2608EDB8, 0x22C9F00F, 0x2F8AD6D6, 0x2B4BCB61, 0x350C9B64, 0x31CD86D3, 0x3C8EA00A, 0x384FBDBD, 0x4C11DB70, 0x48D0C6C7, 0x4593E01E, 0x4152FDA9, 0x5F15ADAC, 0x5BD4B01B, 0x569796C2, 0x52568B75, 0x6A1936C8, 0x6ED82B7F, 0x639B0DA6, 0x675A1011, 0x791D4014, 0x7DDC5DA3, 0x709F7B7A, 0x745E66CD, 0x9823B6E0, 0x9CE2AB57, 0x91A18D8E, 0x95609039, 0x8B27C03C, 0x8FE6DD8B, 0x82A5FB52, 0x8664E6E5, 0xBE2B5B58, 0xBAEA46EF, 0xB7A96036, 0xB3687D81, 0xAD2F2D84, 0xA9EE3033, 0xA4AD16EA, 0xA06C0B5D, 0xD4326D90, 0xD0F37027, 0xDDB056FE, 0xD9714B49, 0xC7361B4C, 0xC3F706FB, 0xCEB42022, 0xCA753D95, 0xF23A8028, 0xF6FB9D9F, 0xFBB8BB46, 0xFF79A6F1, 0xE13EF6F4, 0xE5FFEB43, 0xE8BCCD9A, 0xEC7DD02D, 0x34867077, 0x30476DC0, 0x3D044B19, 0x39C556AE, 0x278206AB, 0x23431B1C, 0x2E003DC5, 0x2AC12072, 0x128E9DCF, 0x164F8078, 0x1B0CA6A1, 0x1FCDBB16, 0x18AEB13, 0x54BF6A4, 0x808D07D, 0xCC9CDCA, 0x7897AB07, 0x7C56B6B0, 0x71159069, 0x75D48DDE, 0x6B93DDDB, 0x6F52C06C, 0x6211E6B5, 0x66D0FB02, 0x5E9F46BF, 0x5A5E5B08, 0x571D7DD1, 0x53DC6066, 0x4D9B3063, 0x495A2DD4, 0x44190B0D, 0x40D816BA, 0xACA5C697, 0xA864DB20, 0xA527FDF9, 0xA1E6E04E, 0xBFA1B04B, 0xBB60ADFC, 0xB6238B25, 0xB2E29692, 0x8AAD2B2F, 0x8E6C3698, 0x832F1041, 0x87EE0DF6, 0x99A95DF3, 0x9D684044, 0x902B669D, 0x94EA7B2A, 0xE0B41DE7, 0xE4750050, 0xE9362689, 0xEDF73B3E, 0xF3B06B3B, 0xF771768C, 0xFA325055, 0xFEF34DE2, 0xC6BCF05F, 0xC27DEDE8, 0xCF3ECB31, 0xCBFFD686, 0xD5B88683, 0xD1799B34, 0xDC3ABDED, 0xD8FBA05A, 0x690CE0EE, 0x6DCDFD59, 0x608EDB80, 0x644FC637, 0x7A089632, 0x7EC98B85, 0x738AAD5C, 0x774BB0EB, 0x4F040D56, 0x4BC510E1, 0x46863638, 0x42472B8F, 0x5C007B8A, 0x58C1663D, 0x558240E4, 0x51435D53, 0x251D3B9E, 0x21DC2629, 0x2C9F00F0, 0x285E1D47, 0x36194D42, 0x32D850F5, 0x3F9B762C, 0x3B5A6B9B, 0x315D626, 0x7D4CB91, 0xA97ED48, 0xE56F0FF, 0x1011A0FA, 0x14D0BD4D, 0x19939B94, 0x1D528623, 0xF12F560E, 0xF5EE4BB9, 0xF8AD6D60, 0xFC6C70D7, 0xE22B20D2, 0xE6EA3D65, 0xEBA91BBC, 0xEF68060B, 0xD727BBB6, 0xD3E6A601, 0xDEA580D8, 0xDA649D6F, 0xC423CD6A, 0xC0E2D0DD, 0xCDA1F604, 0xC960EBB3, 0xBD3E8D7E, 0xB9FF90C9, 0xB4BCB610, 0xB07DABA7, 0xAE3AFBA2, 0xAAFBE615, 0xA7B8C0CC, 0xA379DD7B, 0x9B3660C6, 0x9FF77D71, 0x92B45BA8, 0x9675461F, 0x8832161A, 0x8CF30BAD, 0x81B02D74, 0x857130C3, 0x5D8A9099, 0x594B8D2E, 0x5408ABF7, 0x50C9B640, 0x4E8EE645, 0x4A4FFBF2, 0x470CDD2B, 0x43CDC09C, 0x7B827D21, 0x7F436096, 0x7200464F, 0x76C15BF8, 0x68860BFD, 0x6C47164A, 0x61043093, 0x65C52D24, 0x119B4BE9, 0x155A565E, 0x18197087, 0x1CD86D30, 0x29F3D35, 0x65E2082, 0xB1D065B, 0xFDC1BEC, 0x3793A651, 0x3352BBE6, 0x3E119D3F, 0x3AD08088, 0x2497D08D, 0x2056CD3A, 0x2D15EBE3, 0x29D4F654, 0xC5A92679, 0xC1683BCE, 0xCC2B1D17, 0xC8EA00A0, 0xD6AD50A5, 0xD26C4D12, 0xDF2F6BCB, 0xDBEE767C, 0xE3A1CBC1, 0xE760D676, 0xEA23F0AF, 0xEEE2ED18, 0xF0A5BD1D, 0xF464A0AA, 0xF9278673, 0xFDE69BC4, 0x89B8FD09, 0x8D79E0BE, 0x803AC667, 0x84FBDBD0, 0x9ABC8BD5, 0x9E7D9662, 0x933EB0BB, 0x97FFAD0C, 0xAFB010B1, 0xAB710D06, 0xA6322BDF, 0xA2F33668, 0xBCB4666D, 0xB8757BDA, 0xB5365D03, 0xB1F740B4 };

int main()
{
    string app_version = "v1.0";
    //This should be the process name!
    std::cout << "Ghost Master Randomiser " << app_version << " by Leotachy" << endl;
    std::cout << endl << endl << endl << endl << endl;

    bool RandomiserParameters[10];
    GetRandomiserParameters(RandomiserParameters);

    bool RandHaunters = RandomiserParameters[0];
    bool DialogueFix = RandomiserParameters[1];
    bool RandomDialogue = RandomiserParameters[2];
    bool RandScOrd = RandomiserParameters[3];
    bool PrevImpSav = RandomiserParameters[4];
    


    string *StockHaunterArray = new string[100];
    string *HaunterEnumArray = new string[100];
    string *ActHaunterEnumArray = new string[100];
    string *HaunterScriptInstanceArray = new string[100];

    string HaunterFetterFlagStringArray[100]{};

    string* DialogueHash_arr = new string[1000];
    string* vdDialogueHash_arr = new string[1000];

    string* SpeechName = new string[600];

    int HasManifestPowerBaseKitArray[100]{};
    int SpecialHaunters[10]{};
    int HaunterIDArray[100]{};
    int RemainingRestlessSpiritIDArray[100]{};
    int StockHaunterAndActGiftIDArray[100]{};
    int StockHaunterIDArray[100]{};
    


    int Act2GiftCount = 0;
    int Act3GiftCount = 0;
    int Act4GiftCount = 0;




    srand((unsigned int)time(NULL));
    unsigned seed = rand();


    if (RandScOrd || RandHaunters)
    {

        string ModsPath = GetValidModsPath(RandHaunters);
        int HaunterCount = GetHaunterData(ModsPath, HaunterScriptInstanceArray, HaunterEnumArray, StockHaunterArray, HasManifestPowerBaseKitArray, HaunterIDArray, HaunterFetterFlagStringArray);


        if (RandHaunters)
        {
            GetSpecialHaunters(HasManifestPowerBaseKitArray, seed, HaunterCount, SpecialHaunters, HaunterIDArray, HaunterFetterFlagStringArray, RemainingRestlessSpiritIDArray);



           

            /*for (int i = 0; i < HaunterCount; i++)
            {
                cout << HaunterScriptInstanceArray[i] << endl;
            }*/

            shuffle(RemainingRestlessSpiritIDArray, RemainingRestlessSpiritIDArray + (HaunterCount - 8), default_random_engine(seed)); 

            RandScenario_Haunting101    (ModsPath, app_version, HaunterEnumArray, HaunterScriptInstanceArray, RemainingRestlessSpiritIDArray);
            RandScenario_WeirdSeance    (ModsPath, app_version, HaunterEnumArray, HaunterScriptInstanceArray, RemainingRestlessSpiritIDArray);
            RandScenario_Calamityville  (ModsPath, app_version, HaunterEnumArray, HaunterScriptInstanceArray, RemainingRestlessSpiritIDArray);
            RandScenario_Summoners      (ModsPath, app_version, HaunterEnumArray, HaunterScriptInstanceArray, RemainingRestlessSpiritIDArray, SpecialHaunters);
            RandScenario_Deadfellas     (ModsPath, app_version, HaunterEnumArray, HaunterScriptInstanceArray, RemainingRestlessSpiritIDArray);
            RandScenario_Unusual        (ModsPath, app_version, HaunterEnumArray, HaunterScriptInstanceArray, RemainingRestlessSpiritIDArray);
            RandScenario_Poultrygeist   (ModsPath, app_version, HaunterEnumArray, HaunterScriptInstanceArray, RemainingRestlessSpiritIDArray, SpecialHaunters);
            RandScenario_Facepacks      (ModsPath, app_version, HaunterEnumArray, HaunterScriptInstanceArray, RemainingRestlessSpiritIDArray, SpecialHaunters);
            RandScenario_Phantom        (ModsPath, app_version, HaunterEnumArray, HaunterScriptInstanceArray, RemainingRestlessSpiritIDArray, SpecialHaunters);
            RandScenario_Wisp           (ModsPath, app_version, HaunterEnumArray, HaunterScriptInstanceArray, RemainingRestlessSpiritIDArray, SpecialHaunters);
            RandScenario_Ghostbreakers  (ModsPath, app_version, HaunterEnumArray, HaunterScriptInstanceArray, RemainingRestlessSpiritIDArray);
            RandScenario_MortalJacket   (ModsPath, app_version, HaunterEnumArray, HaunterScriptInstanceArray, RemainingRestlessSpiritIDArray);
            RandScenario_Spooky         (ModsPath, app_version, HaunterEnumArray, HaunterScriptInstanceArray, RemainingRestlessSpiritIDArray, SpecialHaunters);
            RandScenario_Cuckoos        (ModsPath, app_version, HaunterEnumArray, HaunterScriptInstanceArray, RemainingRestlessSpiritIDArray);

            std::cout << "Restless Spirits have been randomised successfully!" << endl;
        

        
            GetActGiftsForEachAct(ModsPath, "ActsGhosts.asm", Act2GiftCount, Act3GiftCount, Act4GiftCount);
            int TotalGiftCount = Act2GiftCount + Act3GiftCount + Act4GiftCount;

           
            int OtherHaunters = GetCountOfOtherHauntersAndSubtractRestlessSpirits(HaunterCount, HaunterIDArray, RemainingRestlessSpiritIDArray, StockHaunterAndActGiftIDArray);

            shuffle(StockHaunterAndActGiftIDArray, StockHaunterAndActGiftIDArray + OtherHaunters, default_random_engine(seed));
            OutputActGifts(ModsPath, "ActsGhosts.asm", HaunterEnumArray, Act2GiftCount, Act3GiftCount, Act4GiftCount, StockHaunterAndActGiftIDArray);
            DeleteAndRename(ModsPath, "ActsGhosts.asm");
            
           

            

            int StockHaunterCount = OtherHaunters - TotalGiftCount;
            SubtractActGifts(StockHaunterAndActGiftIDArray, StockHaunterIDArray, TotalGiftCount, StockHaunterCount);
            shuffle(StockHaunterArray, StockHaunterArray + StockHaunterCount, default_random_engine(seed));
            OutputStockHaunters(ModsPath, "HaunterData.asm", StockHaunterIDArray, StockHaunterCount);
            DeleteAndRename(ModsPath, "HaunterData.asm");

        }

        if (DialogueFix)
        {
            int DialogueCount = GetDialogueHashesAndCountASM(ModsPath, DialogueHash_arr);
            string NewPath = GetPathToEnglishVdTxt(ModsPath);
            if (NewPath == "")
                return 0;
            int vdDialogueCount = GetDialogueHashesTXTAndCount(NewPath, vdDialogueHash_arr, SpeechName, seed);
            
            ClearSoundSubtitles(DialogueHash_arr, vdDialogueHash_arr, vdDialogueCount, DialogueCount);
            if (RandomDialogue)
            {
                RandomiseHaunterDialogue(DialogueHash_arr, DialogueCount, vdDialogueHash_arr, vdDialogueCount, seed);
            }
            int GhostDialogueHashCount = OutputSoundSubtitles(ModsPath, DialogueHash_arr, DialogueCount);
            if (RandomDialogue)
            {
                OutputNarratorSpeechHashes(ModsPath, SpeechName, app_version);
                cout << "Dialogue has been randomised successfully!" << endl;
            }
            if (DeleteAndRename(ModsPath, "SoundSubtitles.asm"))
            {
                cout << "Haunter speech related softlocks have been fixed successfully!" << endl;
            }
        }

        

 

        

        if (RandScOrd)
        {
            
            int ScenarioIndexes[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 }; //H101, WS, CH, SNI, DF, US, FB, PG, PH, BWP, SH, GB, FMJ, CN, FIN 

            

            GetRandomScenarioOrder(PrevImpSav, ScenarioIndexes, seed);

            string Sc_Available_Array[] = { "00951218", "00951250", "00951288", "009512C0", "009512F8", "00951330", "00951368", "009513A0", "009513D8", "00951410", "00951448", "00951480", "009514B8", "009514F0", "00951528" };
            //H101, WS, CH, SNI, DF, US, FB, PG, PH, BWP, SH, GB, FMJ, CN, FIN 
            string Sc_Completed_Array[] = { "00951214", "0095124C", "00951284", "009512BC", "009512F4", "0095132C", "00951364", "0095139C", "009513D4", "0095140C", "00951444", "0095147C", "009514B4", "009514EC", "00951524" }; //Always 4 bytes before available
            string Sc_ScriptInstance_Array[] = { "008C6528", "008C651C", "008C6510", "008C6504", "008C64F8", "008C64F0", "008C64E4", "008C64D4", "008C64CC", "008C5768", "008C64C4", "008C64B4", "008C64A4", "008C6494", "008C6480" };
            string Sc_Name_Array[] = { "0000035F", "00000360", "00000363" , "00000361", "00000362", "00000365", "00000367", "00000366", "0000036C", "00000368", "0000036A", "0000036D", "0000036E", "00000370", "00000902" };

           

            OutputScenarioOrder(ModsPath, app_version, Sc_Available_Array, Sc_Completed_Array, Sc_Name_Array, Sc_ScriptInstance_Array, ScenarioIndexes);

            std::cout << "Scenario Order has been randomised succesfully!" << endl;
        }

        OutputRandomiserInfo(ModsPath, app_version, seed, RandHaunters, RandScOrd, PrevImpSav, DialogueFix, RandomDialogue);

    }

    delete[] StockHaunterArray;
    delete[] HaunterEnumArray;
    delete[] ActHaunterEnumArray;
    delete[] HaunterScriptInstanceArray;

    delete[] DialogueHash_arr;
    delete[] vdDialogueHash_arr;

    delete[] SpeechName;

    

    return 0;
}



void GetRandomiserParameters(bool *RandomiserParameters)
{
    string QuestionStringArray[] = {  "Randomise Haunters? (Y/N): ",
                                      "Fix haunter speech related softlocks? (Y/N): ",
                                      "Randomise Dialogue? (Y/N): ",
                                      "Randomise Scenario Order? (Y/N): ",
                                      "Try to prevent impossible to complete outcomes? (Y/N): " };

    int size = sizeof(QuestionStringArray) / sizeof(*QuestionStringArray);

    string User_Input;

    for (int i = 0; i < size;)
    {

        std::cout << QuestionStringArray[i];
        getline(cin, User_Input);
        std::cout << endl;


        if (User_Input == "Y" || User_Input == "y")
        {
            RandomiserParameters[i] = 1;
            i++;
        }

        if (User_Input == "N" || User_Input == "n")
        {
            RandomiserParameters[i] = 0;
            if (i == 0 && RandomiserParameters[0] != true)
            {
                RandomiserParameters[1] = false;
                i++;
            }
            
            if (i == 3 && RandomiserParameters[3] != true)
            {
                RandomiserParameters[4] = false;
                i++;
            }

            i++;
        }

        if (User_Input != "Y" && User_Input != "y" && User_Input != "N" && User_Input != "n")
        {
            std::cout << "Incorrect parameter! Please type Y (yes) or N (no)" << endl << endl;
        }
    }

}

string GetValidModsPath(bool RandHaunters)
{
    string ModsPath;


    bool error = false;

    


    ifstream CheckIfExists;

    while (69)
    {
        if (error)
        {
            cout << "Example: C:\\Ghost Master\\GhostData\\Mods\\CompleteEdition2copy\\ " << endl;
        }

        retry:
        cout << "Please direct a path to your mod's folder: ";
        getline(cin, ModsPath);
        cout << endl;

        if (ModsPath == "")
        {
            goto retry;
        }

        if (ModsPath.back() != 0x5C) //5C is backwards slash
            ModsPath += 0x5C;

        if (RandHaunters)
        {
            CheckIfExists.open(ModsPath + "HaunterData.asm");
            if (!CheckIfExists)
            {
                std::cout << "Could not find HaunterData.asm" << endl;
                error = true;
            }
            else
            {
                CheckIfExists.close();
                break;
            }

        }
        else
        {
            break;
        }

    }

    return ModsPath;
}



int GetHaunterData(string ModsPath, string* HaunterScriptInstanceArray, string* HaunterEnumArray, string* StockHaunterArray, int* HasManifestPowerBaseKitArray, int* HaunterIDArray, string* HaunterFetterFlagStringArray)
{
    ifstream HaunterData;
    string uselessLine;
    HaunterData.open(ModsPath + "HaunterData.asm");
    bool FirstTime = true;
    bool FirstTimeEnum = true;
    bool FirstTimeScriptInstance = true;
    bool FirstTimePower = true;
    bool FirstTimeFetter = true;

    bool HaunterHasManifestPower = false;

    int e = 0;
    int a = 0;
    int i = 0;
    int z = 0;
    int f = 0;


    int HaunterCount = 0;

    while (uselessLine != "db 21")
    {
        getline(HaunterData, uselessLine);

        HaunterHasManifestPower = false;

        if (((a == 8 && FirstTimeScriptInstance) || a == 43))
        {
            HaunterScriptInstanceArray[HaunterCount] = uselessLine.substr(3, 149);
            //cout << HaunterScriptInstanceArray[HaunterCount] << endl;
            FirstTimeScriptInstance = false;
            a = 0;
        }

        if (((e == 15 && FirstTimeEnum) || e == 43))
        {
            HaunterEnumArray[HaunterCount] = uselessLine.substr(3, 8);
            FirstTimeEnum = false;
            e = 0;
        }

        if ((i == 22 && FirstTime) || i == 43)
        {
            StockHaunterArray[HaunterCount] = uselessLine;
            FirstTime = false;
            i = 0;
        }

        if ((z == 24 && FirstTimePower) || z == 43)
        {
            for (int xd = 0; xd < 10; xd++)
            {
                getline(HaunterData, uselessLine);
                if (uselessLine == "dd 0000003E" || uselessLine == "dd 00000040" || uselessLine == "dd 00000042")
                {
                    HaunterHasManifestPower = true;
                }
            }


            if (HaunterHasManifestPower)
            {
                HasManifestPowerBaseKitArray[HaunterCount] = 1;
            }

            else
            {
                HasManifestPowerBaseKitArray[HaunterCount] = 0;
            }

            FirstTimePower = false;
            z = 0;

        }
       
        if ((f == 44 && FirstTimeFetter) || (f == 43 && !FirstTimeFetter))
        {
            FirstTimeFetter = false;

            HaunterFetterFlagStringArray[HaunterCount] = uselessLine.substr(3, 8);
            HaunterIDArray[HaunterCount] = HaunterCount;
            HaunterCount++;
            f = 0;
        }

        e++;
        a++;
        i++;
        z++;
        f++;
    }

    HaunterData.close();

    return HaunterCount;
}




void OutputStockHaunters(string ModsPath, string fileName, int* StockHaunterIDArray, int StockHaunterCount)
{

    ifstream filein(ModsPath + fileName);
    ofstream fileout(ModsPath + fileName + ".Randomiser_TEMP");

    string strTemp;

    bool firstTime = true;
    bool BecomeStockHaunter = false;
    bool startCopying = false;

    int i = 0;
    int HaunterIDCount = 0;

    for (i = 0; filein; i++)
    {
        getline(filein, strTemp);

        if (strTemp == "[ENABLE]")
        {
            startCopying = true;
        }

        if (!startCopying)
        {
            BecomeStockHaunter = false;
            
            if ((i == 22 && firstTime) || i == 53)
            {  
                firstTime = false;
                i = 0;
                for (int xaxa = 0; xaxa < StockHaunterCount; xaxa++)
                {
                    if (HaunterIDCount == StockHaunterIDArray[xaxa])
                    {
                        BecomeStockHaunter = true;
                        goto escapeLoop;
                    }
                }

            escapeLoop:
                if (BecomeStockHaunter == true)
                {
                    strTemp = "dd 00000001";
                }
                else
                {
                    strTemp = "dd 00000000";
                }

                HaunterIDCount++;
            }
        }
        
        fileout << strTemp << endl;
    }
    

       

      

    
        

        
    
}

void GetActGiftsForEachAct(string ModsPath, string fileName, int& Act2GiftCount, int& Act3GiftCount, int& Act4GiftCount)
{
    ifstream filein;
    string strTemp;
    bool StartCountingAct3Gifts = false;
    bool StartCountingAct4Gifts = false;

    filein.open(ModsPath + fileName);

    int jibat = 0;


    while (true)
    {
        getline(filein, strTemp);
        if (strTemp.substr(0, 3) == "Act")
        {
            while (strTemp != "[ENABLE]")
            {
                getline(filein, strTemp);
                if (strTemp.substr(0, 4) == "push")
                {
                    if (StartCountingAct4Gifts)
                        Act4GiftCount++;
                    else
                    {
                        if (!StartCountingAct3Gifts)
                            Act2GiftCount++;
                        else
                            Act3GiftCount++;
                    }
                    jibat++;
                }


                if (strTemp.substr(0, 3) == "jmp" && StartCountingAct3Gifts)
                {
                    StartCountingAct3Gifts = false;
                    StartCountingAct4Gifts = true;
                }

                if (strTemp.substr(0, 3) == "jmp")
                {
                    StartCountingAct3Gifts = true;
                }
            }

            filein.close();
            break;
        }

        
    }
    
}

void RandomiseHaunterDialogue(string* DialogueHash_arr, int DialogueCount, string* vdDialogueHash_arr, int vdDialogueCount, unsigned seed)
{
    shuffle(vdDialogueHash_arr, vdDialogueHash_arr + vdDialogueCount, default_random_engine(seed));

    int u = 0;

    for (int i = 0; i < DialogueCount; i++)
    {
        if (DialogueHash_arr[i] == "00000000")
        {
            DialogueHash_arr[i] = vdDialogueHash_arr[u];
            u++;
        }
    }

    shuffle(DialogueHash_arr, DialogueHash_arr + DialogueCount, default_random_engine(seed));
}

void OutputNarratorSpeechHashes(string ModsPath, string* SpeechName, string app_version)
{
    ofstream OutputASM(ModsPath + "Random_NarratorSpeech.asm");

    OutputASM << "//File generated by Leotachy's Ghost Master Randomiser " << app_version << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << "[ENABLE]" << endl;
    OutputASM << endl;
    OutputASM << "alloc(newmem,500)" << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << "newmem:" << endl;
    OutputASM << "NameEntry1:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[0]) << endl;
    OutputASM << "NameEntry2:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[1]) << endl;
    OutputASM << "NameEntry3:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[2]) << endl;

    OutputASM << "Act1:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[3]) << endl;
    OutputASM << "Act2:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[4]) << endl;
    OutputASM << "Act3:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[5]) << endl;

    OutputASM << "ExtraCommitee3:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[6]) << endl;
    OutputASM << "ExtraCommitee4:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[7]) << endl;
    OutputASM << "ExtraCommitee10:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[8]) << endl;

    OutputASM << "H101_Intro1:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[9]) << endl;
    OutputASM << "H101_Intro2:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[10]) << endl;

    OutputASM << "WS_Intro1:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[11]) << endl;
    OutputASM << "WS_Intro2:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[12]) << endl;

    OutputASM << "CH_Intro1:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[13]) << endl;
    OutputASM << "CH_Intro2:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[14]) << endl;
    OutputASM << "CH_Fail:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[15]) << endl;
    OutputASM << "CH_Handyman:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[16]) << endl;
    OutputASM << "CH_Police:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[17]) << endl;
    OutputASM << "CH_Witches:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[18]) << endl;
    OutputASM << "CH_WarningFlee:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[19]) << endl;
    OutputASM << "CH_MortalCorpse1:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[20]) << endl;
    OutputASM << "CH_MortalCorpse2:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[21]) << endl;
    OutputASM << "CH_PoliceCorpse1:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[22]) << endl;
    OutputASM << "CH_PoliceCorpse2:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[23]) << endl;

    OutputASM << "SNI_Intro1:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[24]) << endl;
    OutputASM << "SNI_Intro2:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[25]) << endl;
    OutputASM << "SNI_Warning:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[26]) << endl;
    OutputASM << "SNI_Won:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[27]) << endl;
    OutputASM << "SNI_Update:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[28]) << endl;
    OutputASM << "SNI_MovBook:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[29]) << endl;

    OutputASM << "DF_Intro1:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[30]) << endl;
    OutputASM << "DF_Intro2:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[31]) << endl;
    OutputASM << "DF_Minor:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[32]) << endl;
    OutputASM << "DF_Major:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[33]) << endl;
    OutputASM << "DF_Warning:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[34]) << endl;
    OutputASM << "DF_Pump:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[35]) << endl;

    OutputASM << "US_Intro1:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[36]) << endl;
    OutputASM << "US_Intro2:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[37]) << endl;

    OutputASM << "FP_Intro1:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[38]) << endl;
    OutputASM << "FP_Intro2:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[39]) << endl;
    OutputASM << "FP_Broken:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[40]) << endl;
    OutputASM << "FP_Disabled:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[41]) << endl;

    OutputASM << "PG_Intro1:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[42]) << endl;
    OutputASM << "PG_Intro2:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[43]) << endl;
    OutputASM << "PG_Medium:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[44]) << endl;
    OutputASM << "PG_Ghostbreaker:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[45]) << endl;
    OutputASM << "PG_Banished:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[46]) << endl;


    OutputASM << "BWP_Intro1:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[47]) << endl;
    OutputASM << "BWP_Intro2:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[48]) << endl;
    OutputASM << "BWP_Succeed:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[49]) << endl;
    OutputASM << "BWP_Repeat:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[50]) << endl;
    OutputASM << "BWP_Bridge:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[51]) << endl;

    OutputASM << "SH_Intro1:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[52]) << endl;
    OutputASM << "SH_Intro2:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[53]) << endl;
    OutputASM << "SH_Help9:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[54]) << endl;
    OutputASM << "SH_Help8:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[55]) << endl;
    OutputASM << "SH_Help4:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[56]) << endl;

    OutputASM << "PH_Intro1:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[57]) << endl;
    OutputASM << "PH_Intro2:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[58]) << endl;
    OutputASM << "PH_Ghostbreakers:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[59]) << endl;

    OutputASM << "GB_Intro1:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[60]) << endl;
    OutputASM << "GB_Intro2:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[61]) << endl;
    OutputASM << "GB_ESD1:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[62]) << endl;
    OutputASM << "GB_ESD2:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[63]) << endl;
    OutputASM << "GB_Windwalker1:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[64]) << endl;
    OutputASM << "GB_Windwalker2:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[65]) << endl;
    OutputASM << "GB_Banzai1:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[66]) << endl;
    OutputASM << "GB_Banzai2:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[67]) << endl;
    OutputASM << "GB_BlueMurder1:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[68]) << endl;
    OutputASM << "GB_BlueMurder2:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[69]) << endl;
    OutputASM << "GB_Electrospasm1:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[70]) << endl;
    OutputASM << "GB_Electrospasm2:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[71]) << endl;
    OutputASM << "GB_Arclight1:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[72]) << endl;
    OutputASM << "GB_Arclight2:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[73]) << endl;
    OutputASM << "GB_Static1:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[74]) << endl;
    OutputASM << "GB_Static2:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[75]) << endl;
    OutputASM << "GB_Maxine1:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[76]) << endl;
    OutputASM << "GB_Maxine2:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[77]) << endl;
    OutputASM << "GB_GreenWardDisabled:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[78]) << endl;
    OutputASM << "GB_GreenWardBroken:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[79]) << endl;
    OutputASM << "GB_BlueWardBroken:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[80]) << endl;
    OutputASM << "GB_RedWardBroken:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[81]) << endl;
    OutputASM << "GB_AlarmTriggered:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[82]) << endl;
    OutputASM << "GB_AlarmBroken:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[83]) << endl;

    OutputASM << "FMJ_Intro:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[84]) << endl;
    OutputASM << "FMJ_Intro2:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[85]) << endl;

    OutputASM << "CN_Intro1:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[86]) << endl;
    OutputASM << "CN_Intro2:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[87]) << endl;
    OutputASM << "CN_Bruce:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[88]) << endl;
    OutputASM << "CN_EZWIN:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[89]) << endl;
    OutputASM << "CN_D1:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[90]) << endl;
    OutputASM << "CN_D2:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[91]) << endl;
    OutputASM << "CN_DL:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[92]) << endl;

    OutputASM << "Fin1:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[93]) << endl;
    OutputASM << "Fin2:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[94]) << endl;
    OutputASM << "Fin3:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[95]) << endl;
    OutputASM << "Fin4:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[96]) << endl;
    OutputASM << "Fin5:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[97]) << endl;
    OutputASM << "Fin6:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[98]) << endl;
    OutputASM << "Fin7:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[99]) << endl;
    OutputASM << "Fin8:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[100]) << endl;
    OutputASM << "Fin9:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[101]) << endl;
    OutputASM << "Fin10:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[102]) << endl;
    OutputASM << "Fin12:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[103]) << endl;
    OutputASM << "Fin13:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[104]) << endl;
    OutputASM << "Fin14:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[405]) << endl;
    OutputASM << "Fin15:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[106]) << endl;
    OutputASM << "Fin16:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[107]) << endl;
    OutputASM << "Fin17:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[108]) << endl;
    OutputASM << "Fin18:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[109]) << endl;
    OutputASM << "Fin19:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[110]) << endl;
    OutputASM << "Fin20:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[111]) << endl;
    OutputASM << "Fin21:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[112]) << endl;
    OutputASM << "Fin23:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[113]) << endl;
    OutputASM << "Fin24:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[114]) << endl;
    OutputASM << "Fin25:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[115]) << endl;
    OutputASM << "Fin30:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[116]) << endl;
    OutputASM << "Fin31:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[117]) << endl;
    OutputASM << "Fin32:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[118]) << endl;
    OutputASM << "Fin33:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[119]) << endl;
    OutputASM << "Fin34:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[120]) << endl;
    OutputASM << "Fin35:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[121]) << endl;
    OutputASM << "Fin36:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[122]) << endl;
    OutputASM << "Fin37:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[123]) << endl;
    OutputASM << "Fin38:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[124]) << endl;
    OutputASM << "Fin39:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[125]) << endl;
    OutputASM << "Fin40:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[126]) << endl;
    OutputASM << "Fin41:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[127]) << endl;
    OutputASM << "Fin42:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[128]) << endl;
    OutputASM << "Fin43:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[129]) << endl;
    OutputASM << "Fin44:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[130]) << endl;
    OutputASM << "Fin45:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[131]) << endl;
    OutputASM << "Fin46:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[132]) << endl;
    OutputASM << "Fin47:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[133]) << endl;
    OutputASM << "Fin48:" << endl;
    OutputASM << "db " << string_to_hex(SpeechName[134]) << endl;








    OutputASM << "00440CD3:" << endl;
    OutputASM << "push NameEntry1" << endl;
    OutputASM << "004416DA: " << endl;
    OutputASM << "push NameEntry2" << endl;
    OutputASM << "00441719: " << endl;
    OutputASM << "push NameEntry3" << endl;

    OutputASM << "00441CFE:" << endl;
    OutputASM << "mov [009468BC],Act1" << endl;
    OutputASM << "00441BF7: " << endl;
    OutputASM << "mov [009468BC],Act2" << endl;
    OutputASM << "00441BF7: " << endl;
    OutputASM << "mov [009468BC],Act2" << endl;
    OutputASM << "00441C58: " << endl;
    OutputASM << "mov [009468BC],Act3" << endl;
    OutputASM << "00441C77: " << endl;
    OutputASM << "mov [009468BC],Act3" << endl;

    OutputASM << "00526B33:" << endl;
    OutputASM << "push ExtraCommitee3" << endl;
    OutputASM << "00526338: " << endl;
    OutputASM << "push ExtraCommitee4" << endl;
    OutputASM << "005065C5: " << endl;
    OutputASM << "push ExtraCommitee10" << endl;

    OutputASM << "005325B4: " << endl;
    OutputASM << "push H101_Intro1" << endl;
    OutputASM << "005325C8: " << endl;
    OutputASM << "push H101_Intro2" << endl;

    OutputASM << "005538B5: " << endl;
    OutputASM << "push WS_Intro1" << endl;
    OutputASM << "005538C9: " << endl;
    OutputASM << "push WS_Intro2" << endl;

    OutputASM << "0050631B: " << endl;
    OutputASM << "push CH_Intro1" << endl;
    OutputASM << "0050632F: " << endl;
    OutputASM << "push CH_Intro2" << endl;
    OutputASM << "00506639: " << endl;
    OutputASM << "push CH_Fail" << endl;
    OutputASM << "0050F2E2: " << endl;
    OutputASM << "push CH_Handyman" << endl;
    OutputASM << "0050632F: " << endl;
    OutputASM << "push CH_Police" << endl;
    OutputASM << "00508907: " << endl;
    OutputASM << "push CH_Witches" << endl;
    OutputASM << "005067BB: " << endl;
    OutputASM << "push CH_WarningFlee" << endl;
    OutputASM << "005064E4: " << endl;
    OutputASM << "push CH_MortalCorpse1" << endl;
    OutputASM << "005064DD: " << endl;
    OutputASM << "push CH_MortalCorpse1" << endl;
    OutputASM << "00506552: " << endl;
    OutputASM << "push CH_PoliceCorpse1" << endl;
    OutputASM << "00506621: " << endl;
    OutputASM << "push CH_PoliceCorpse2" << endl;

    OutputASM << "004F7ACD: " << endl;
    OutputASM << "push SNI_Intro1" << endl;
    OutputASM << "004F7AE1: " << endl;
    OutputASM << "push SNI_Intro2" << endl;
    OutputASM << "004ECA66: " << endl;
    OutputASM << "push SNI_Warning" << endl;
    OutputASM << "004FB78B: " << endl;
    OutputASM << "push SNI_Won" << endl;
    OutputASM << "004FCE79: " << endl;
    OutputASM << "push SNI_Update" << endl;
    OutputASM << "004FD7CA: " << endl;
    OutputASM << "push SNI_MovBook" << endl;

    OutputASM << "00516F21: " << endl;
    OutputASM << "push DF_Intro1" << endl;
    OutputASM << "00516F35: " << endl;
    OutputASM << "push DF_Intro2" << endl;
    OutputASM << "005173C4: " << endl;
    OutputASM << "push DF_Minor" << endl;
    OutputASM << "005173FE: " << endl;
    OutputASM << "push DF_Major" << endl;
    OutputASM << "005174A2: " << endl;
    OutputASM << "push DF_Warning" << endl;
    OutputASM << "005177F4: " << endl;
    OutputASM << "push DF_Pump" << endl;

    OutputASM << "0052E084: " << endl;
    OutputASM << "push US_Intro1" << endl;
    OutputASM << "0052E098: " << endl;
    OutputASM << "push US_Intro2" << endl;

    OutputASM << "0053CA21: " << endl;
    OutputASM << "push FP_Intro1" << endl;
    OutputASM << "0053CA35: " << endl;
    OutputASM << "push FP_Intro2" << endl;
    OutputASM << "00538CD9: " << endl;
    OutputASM << "push FP_Broken" << endl;
    OutputASM << "00539035: " << endl;
    OutputASM << "push FP_Disabled" << endl;

    OutputASM << "0050A06B: " << endl;
    OutputASM << "push PG_Intro1" << endl;
    OutputASM << "0050A07F: " << endl;
    OutputASM << "push PG_Intro2" << endl;
    OutputASM << "0050A5AB: " << endl;
    OutputASM << "push PG_Ghostbreaker" << endl;
    OutputASM << "0050A224: " << endl;
    OutputASM << "push PG_Banished" << endl;
    OutputASM << "0050AD9C: " << endl;
    OutputASM << "push PG_Medium" << endl;

    OutputASM << "004DF6E2: " << endl;
    OutputASM << "push PH_Intro1" << endl;
    OutputASM << "004DF6F6: " << endl;
    OutputASM << "push PH_Intro2" << endl;
    OutputASM << "004E19D0: " << endl;
    OutputASM << "push PH_Ghostbreakers" << endl;



    OutputASM << "004EC404: " << endl;
    OutputASM << "push BWP_Intro1" << endl;
    OutputASM << "004EC418: " << endl;
    OutputASM << "push BWP_Intro2" << endl;
    OutputASM << "004F5424: " << endl;
    OutputASM << "push BWP_Succeed" << endl;
    OutputASM << "004F5442: " << endl;
    OutputASM << "push BWP_Succeed" << endl;
    OutputASM << "004EC917: " << endl;
    OutputASM << "push BWP_Repeat" << endl;
    OutputASM << "004EC9B3: " << endl;
    OutputASM << "push BWP_Bridge" << endl;

    OutputASM << "0054A8DD: " << endl;
    OutputASM << "push SH_Intro1" << endl;
    OutputASM << "0054A8F2: " << endl;
    OutputASM << "push SH_Intro2" << endl;
    OutputASM << "005420E5: " << endl;
    OutputASM << "push SH_Help9" << endl;
    OutputASM << "00541E4E: " << endl;
    OutputASM << "push SH_Help8" << endl;
    OutputASM << "0054672E: " << endl;
    OutputASM << "push SH_Help4" << endl;

    OutputASM << "0052198B: " << endl;
    OutputASM << "push GB_Intro1" << endl;
    OutputASM << "0052199F: " << endl;
    OutputASM << "push GB_Intro2" << endl;
    OutputASM << "0051F142: " << endl;
    OutputASM << "push GB_ESD1" << endl;
    OutputASM << "0051E96D: " << endl;
    OutputASM << "push GB_ESD2" << endl;
    OutputASM << "0051EB5B: " << endl;
    OutputASM << "push GB_Windwalker1" << endl;
    OutputASM << "0051EB6A: " << endl;
    OutputASM << "push GB_Windwalker2" << endl;
    OutputASM << "0051EB33: " << endl;
    OutputASM << "push GB_Banzai1" << endl;
    OutputASM << "0051EB3D: " << endl;
    OutputASM << "push GB_Banzai2" << endl;
    OutputASM << "0051EAFE: " << endl;
    OutputASM << "push GB_BlueMurder1" << endl;
    OutputASM << "0051EB0D: " << endl;
    OutputASM << "push GB_BlueMurder2" << endl;
    OutputASM << "0051EAD1: " << endl;
    OutputASM << "push GB_Electrospasm1" << endl;
    OutputASM << "0051EAE0: " << endl;
    OutputASM << "push GB_Electrospasm2" << endl;
    OutputASM << "0051EA4A: " << endl;
    OutputASM << "push GB_Arclight1" << endl;
    OutputASM << "0051EA59: " << endl;
    OutputASM << "push GB_Arclight2" << endl;
    OutputASM << "0051EA77: " << endl;
    OutputASM << "push GB_Static1" << endl;
    OutputASM << "0051EA86: " << endl;
    OutputASM << "push GB_Static2" << endl;
    OutputASM << "0051EAA4: " << endl;
    OutputASM << "push GB_Maxine1" << endl;
    OutputASM << "0051EAB3: " << endl;
    OutputASM << "push GB_Maxine2" << endl;
    OutputASM << "0051E7AE: " << endl;
    OutputASM << "push GB_GreenWardDisabled" << endl;
    OutputASM << "0051E6FF: " << endl;
    OutputASM << "push GB_GreenWardBroken" << endl;
    OutputASM << "0051E3B0: " << endl;
    OutputASM << "push GB_BlueWardBroken" << endl;
    OutputASM << "0051F058: " << endl;
    OutputASM << "push GB_RedWardBroken" << endl;
    OutputASM << "0051D347: " << endl;
    OutputASM << "push GB_AlarmTriggered" << endl;
    OutputASM << "0051D616: " << endl;
    OutputASM << "push GB_AlarmBroken" << endl;

    OutputASM << "004D08B2: " << endl;
    OutputASM << "push FMJ_Intro" << endl;
    OutputASM << "004D08C6: " << endl;
    OutputASM << "push FMJ_Intro2" << endl;


    OutputASM << "004D9346: " << endl;
    OutputASM << "push CN_Intro1" << endl;
    OutputASM << "004D935A: " << endl;
    OutputASM << "push CN_Intro2" << endl;
    OutputASM << "004DB838: " << endl;
    OutputASM << "push CN_Bruce" << endl;
    OutputASM << "004DB692: " << endl;
    OutputASM << "push CN_EZWIN" << endl;
    OutputASM << "004DA968: " << endl;
    OutputASM << "push CN_D1" << endl;
    OutputASM << "004DA989: " << endl;
    OutputASM << "push CN_D2" << endl;
    OutputASM << "004DA9A4: " << endl;
    OutputASM << "push CN_DL" << endl;


    OutputASM << "0055F557: " << endl;
    OutputASM << "push Fin1" << endl;
    OutputASM << "0055F56B: " << endl;
    OutputASM << "push Fin2" << endl;
    OutputASM << "00558761: " << endl;
    OutputASM << "push Fin3" << endl;
    OutputASM << "0055BE00: " << endl;
    OutputASM << "push Fin4" << endl;
    OutputASM << "0055B631: " << endl;
    OutputASM << "push Fin5" << endl;
    OutputASM << "008E4D90: " << endl;
    OutputASM << "push Fin6" << endl;
    OutputASM << "0055BF35: " << endl;
    OutputASM << "push Fin7" << endl;
    OutputASM << "0055B6B5: " << endl;
    OutputASM << "push Fin8" << endl;
    OutputASM << "0055BD6E: " << endl;
    OutputASM << "push Fin9" << endl;
    OutputASM << "00576FD5: " << endl;
    OutputASM << "push Fin10" << endl;
    OutputASM << "0055A362: " << endl;
    OutputASM << "push Fin12" << endl;
    OutputASM << "0055A4EF: " << endl;
    OutputASM << "push Fin13" << endl;
    OutputASM << "00557FD7: " << endl;
    OutputASM << "push Fin14" << endl;
    OutputASM << "00558060: " << endl;
    OutputASM << "push Fin15" << endl;
    OutputASM << "00557EA0: " << endl;
    OutputASM << "push Fin16" << endl;
    OutputASM << "0055822E: " << endl;
    OutputASM << "push Fin17" << endl;
    OutputASM << "00556214: " << endl;
    OutputASM << "push Fin18" << endl;
    OutputASM << "00556263: " << endl;
    OutputASM << "push Fin19" << endl;
    OutputASM << "0055ABA6: " << endl;
    OutputASM << "push Fin20" << endl;
    OutputASM << "0055ADF1: " << endl;
    OutputASM << "push Fin21" << endl;
    OutputASM << "0055621B: " << endl;
    OutputASM << "push Fin23" << endl;
    OutputASM << "0055626A: " << endl;
    OutputASM << "push Fin24" << endl;
    OutputASM << "0055AC1B: " << endl;
    OutputASM << "push Fin25" << endl;
    OutputASM << "0055B149: " << endl;
    OutputASM << "push Fin30" << endl;
    OutputASM << "0055B155: " << endl;
    OutputASM << "push Fin31" << endl;
    OutputASM << "0055B16B: " << endl;
    OutputASM << "push Fin32" << endl;
    OutputASM << "0055B181: " << endl;
    OutputASM << "push Fin33" << endl;
    OutputASM << "0055B197: " << endl;
    OutputASM << "push Fin34" << endl;
    OutputASM << "0055B1AD: " << endl;
    OutputASM << "push Fin35" << endl;
    OutputASM << "0055B1C3: " << endl;
    OutputASM << "push Fin36" << endl;
    OutputASM << "0055B1D9: " << endl;
    OutputASM << "push Fin37" << endl;
    OutputASM << "0055B1EF: " << endl;
    OutputASM << "push Fin38" << endl;
    OutputASM << "0055B205: " << endl;
    OutputASM << "push Fin39" << endl;
    OutputASM << "0055B21B: " << endl;
    OutputASM << "push Fin40" << endl;
    OutputASM << "0055B237: " << endl;
    OutputASM << "push Fin41" << endl;
    OutputASM << "0055B253: " << endl;
    OutputASM << "push Fin42" << endl;
    OutputASM << "0055B26F: " << endl;
    OutputASM << "push Fin43" << endl;
    OutputASM << "0055B28B: " << endl;
    OutputASM << "push Fin44" << endl;
    OutputASM << "0055B2A7: " << endl;
    OutputASM << "push Fin45" << endl;
    OutputASM << "0055C5D6: " << endl;
    OutputASM << "push Fin46" << endl;
    OutputASM << "0055C812: " << endl;
    OutputASM << "push Fin47" << endl;
    OutputASM << "0055C64B: " << endl;
    OutputASM << "push Fin48" << endl;






    OutputASM << endl;
    OutputASM << "[DISABLE]" << endl;
    OutputASM << endl;
    OutputASM << "dealloc(newmem)" << endl;

    OutputASM.close();


}

string string_to_hex(const string& input)
{
    static const char hex_digits[] = "0123456789ABCDEF";

    string output;
    output.reserve(input.length() * 2);
    for (unsigned char c : input)
    {
        output.push_back(hex_digits[c >> 4]);
        output.push_back(hex_digits[c & 15]);
        output += " ";
    }
    return output + "00";
}




void OutputActGifts(string ModsPath, string fileName, string* HaunterEnumArray, int Act2GiftCount, int Act3GiftCount, int Act4GiftCount, int* StockHaunterAndActGiftIDArray)
{
    ifstream filein(ModsPath + fileName);
    ofstream fileout(ModsPath + fileName + ".Randomiser_TEMP");

    string strTemp;

    int HaunterCount = 0;
    bool firstTime = true;

    bool Act2GiftsExist = false;
    bool Act3GiftsExist = false;
    bool Act4GiftsExist = false;

    if (Act2GiftCount > 0)
    {
        Act2GiftsExist = true;
    }
    
    if (Act3GiftCount > 0)
    {
        Act3GiftsExist = true;
    }

    if (Act4GiftCount > 0)
    {
        Act4GiftsExist = true;
    }


    for (int i = 0; i < 13; i++) //Until Act2
    {
        getline(filein, strTemp);
        strTemp += "\n";
        fileout << strTemp;
    }
   
    for (int i = 1; Act2GiftCount > 0; i++) //Act2
    {
        getline(filein, strTemp);

        if (i == 1)
        {
            strTemp = "push " + HaunterEnumArray[(StockHaunterAndActGiftIDArray[HaunterCount])];
            HaunterCount++;
            Act2GiftCount--;
            i = -1;
        }

        strTemp += "\n";
        fileout << strTemp;
    }

    
    if (Act2GiftsExist)
    {
        for (int i = 0; i < 4; i++) //Between
        {
            getline(filein, strTemp);
            strTemp += "\n";
            fileout << strTemp;
        }
    }

    else
    {
        for (int i = 0; i < 2; i++) //Between
        {
            getline(filein, strTemp);
            strTemp += "\n";
            fileout << strTemp;
        }
    }

    

    for (int i = 1; Act3GiftCount > 0; i++) //Act3
    {
        getline(filein, strTemp);

        if (i == 1)
        {
            strTemp = "push " + HaunterEnumArray[(StockHaunterAndActGiftIDArray[HaunterCount])];
            HaunterCount++;
            Act3GiftCount--;
            i = -1;
        }

        strTemp += "\n";
        fileout << strTemp;
    }

    if (Act3GiftsExist)
    {
        for (int i = 0; i < 5; i++) //Between
        {
            getline(filein, strTemp);
            strTemp += "\n";
            fileout << strTemp;
        }
    }

    else
    {
        for (int i = 0; i < 3; i++) //Between
        {
            getline(filein, strTemp);
            strTemp += "\n";
            fileout << strTemp;
        }
    }

    for (int i = 1; Act4GiftCount > 0; i++) //Act4
    {
        getline(filein, strTemp);

        if (i == 1)
        {
            strTemp = "push " + HaunterEnumArray[(StockHaunterAndActGiftIDArray[HaunterCount])];
            HaunterCount++;
            Act4GiftCount--;
            i = -1;
        }

        strTemp += "\n";
        fileout << strTemp;
    }

    if (Act4GiftsExist)
    {
        for (int i = 0; i < 29; i++) //After
        {
            getline(filein, strTemp);
            strTemp += "\n";
            fileout << strTemp;
        }
    }

    else
    {
        for (int i = 0; i < 27; i++) //After
        {
            getline(filein, strTemp);
            strTemp += "\n";
            fileout << strTemp;
        }
    }
}



void SubtractActGifts(int* StockHaunterAndActGiftIDArray, int* StockHaunterArray, int ActGiftCount, int StockHaunterCount)
{
    int u = 0;

    for (int i = ActGiftCount; i < (ActGiftCount + StockHaunterCount); i++)
    {
        StockHaunterArray[u] = StockHaunterAndActGiftIDArray[i];
        u++;
    }
}

int GetStockHaunterCount(int HaunterCount, string* StockHaunterArray)
{
    int StockHaunterCount = 0;

    for (int i = 0; i < HaunterCount; i++)
    {
        if (StockHaunterArray[i] == "dd 00000001")
        {
            StockHaunterCount++;
        }
    }

    return StockHaunterCount;
}

int GetCountOfOtherHauntersAndSubtractRestlessSpirits(int HaunterCount, int* HaunterIDArray, int* RestlessSpiritIDArray, int* StockHaunterAndActGiftIDArray)
{
    int u = 0;
    for (int i = 25; i < HaunterCount - 8; i++)
    {
        StockHaunterAndActGiftIDArray[u] = RestlessSpiritIDArray[i];
        u++;
    }

    return u;

}




void GetRandomScenarioOrder(bool PreventImpSaves, int ScenarioIndexes[], unsigned seed)
{

    if (PreventImpSaves)
    {
        int TempArray[20] = {1, 2, 3, 4, 5, 6, 7, 9, 10, 11, 13, 15}; //Scenario indexes that dont matter when they appear
            

        int size = 15;

        shuffle(TempArray, TempArray + 12, default_random_engine(seed));

        bool Summoners = false;
        bool BlairWisp = false;
        bool CuckoosNestInAlready = false;
        

        int test[15]{};

        int ScenarioCount = 13;

        for (int i = 0; i < size; i++)
        {


            if (TempArray[i] == 4)
                Summoners = true;
            if (TempArray[i] == 10)
                BlairWisp = true;
            if (TempArray[i] == 3)
            {
       
                test[0] = 8;
                int a = 1;
                while ((i + a) < ScenarioCount)
                {
                    test[a] = TempArray[i + a];
                    //cout << test[a] << endl;
                    a++;
                }

                //cout << test[0] << endl;
                a--;
                shuffle(test, test + a, default_random_engine(seed));
                int b = i + 1;
                int j = 0;
                while (b < ScenarioCount)
                {
                    TempArray[b] = test[j];
                    //cout << TempArray[b] << endl;
                    b++;
                    j++;
                }

                ScenarioCount++;
            }

            if (TempArray[i] == 6)
            {
                test[0] = 12;
                int a = 1;
                while ((i + a) < ScenarioCount)
                {

                    test[a] = TempArray[i + a];
                    //cout << test[a] << endl;
                    a++;
                }
                //cout << test[0] << endl;
                a--;
                shuffle(test, test + a, default_random_engine(seed));
                int b = i + 1;
                int j = 0;
                while (b < ScenarioCount)
                {
                    TempArray[b] = test[j];
                    //cout << TempArray[b] << endl;
                    b++;
                    j++;
                }
                ScenarioCount++;
            }

            if ((Summoners == true && BlairWisp && true) && CuckoosNestInAlready != true)
            {
                test[0] = 14;
                int a = 1;
                while ((i + a) < ScenarioCount)
                {
                    test[a] = TempArray[i + a];
                    //cout << test[a] << endl;
                    a++;
                }
                //cout << test[0] << endl;
                a--;
                shuffle(test, test + a, default_random_engine(seed));
                int b = i + 1;
                int j = 0;
                while (b < ScenarioCount)
                {
                    TempArray[b] = test[j];
                    //cout << TempArray[b] << endl;
                    b++;
                    j++;
                }
                ScenarioCount++;
                CuckoosNestInAlready = true;
            }

        }

        for (int i = 0; i < 15; i++)
        {
            ScenarioIndexes[i] = TempArray[i] - 1;
            //cout << ScenarioIndexes[i] << endl;
        }

    }

    else
    {
        shuffle(ScenarioIndexes, ScenarioIndexes + 15, default_random_engine(seed));
    }

        
}

int GetDialogueHashesAndCountASM(string ModsPath, string DialogueHash_arr[])
{
    ifstream ASM_input(ModsPath + "SoundSubtitles.asm");


    string TempString;

    int i = 0;

    while(TempString != "[ENABLE]")
    {
        getline(ASM_input, TempString);
        if (TempString.substr(0, 2) == "db")
        {
            TempString = TempString.substr(3, 11);
            std::string::iterator end_pos = std::remove(TempString.begin(), TempString.end(), ' ');
            TempString.erase(end_pos, TempString.end());

            DialogueHash_arr[i] = TempString;
            //cout << DialogueHash_arr[i] << endl;
            i++;
        }
    }

    ASM_input.close();

    return i;
}

string GetPathToEnglishVdTxt(string ModsPath)
{
    int i = 0;
    char temp = ModsPath[i];
    int BackslashCount = 0;
    while (temp)
    {
        temp = ModsPath[i];
        if (temp == '\\')
        {
            BackslashCount++;
        }
        i++;
    }

    //cout << BackslashCount << " This is the backslash count :) " << endl;

    int BackslashTreshold = BackslashCount - 2;
    BackslashCount = 0;

    string NewPath = "";

    for (int i = 0; BackslashCount != BackslashTreshold; i++)
    {
        if (ModsPath[i] == '\\')
            BackslashCount++;

        NewPath += ModsPath[i];
    }

    NewPath += "voice\\english\\english_vd.txt";

    ifstream CheckIfExists;
    CheckIfExists.open(NewPath);
    if (!CheckIfExists)
    {
        cout << "Couldn't find english_vd.txt";
        CheckIfExists.close();
        return "";
    }
    else
    {
        CheckIfExists.close();
        return NewPath;
    }
        
}

int GetDialogueHashesTXTAndCount(string NewPath, string* vdDialogueHash_arr, string* SpeechName, unsigned seed) {

    ifstream inputTXT(NewPath);

    string TempString;

    char checker;

    int hashCount = 0;

    while (inputTXT) {

        getline(inputTXT, TempString);

        if (
            TempString[0]
            && TempString[0] != '#' 
            && TempString.substr(0, 9) != "TUTORIAL_"
            /*&& (TempString.find("BENCH", 0) == string::npos)
            && (TempString.find("DISPEL", 0) == string::npos)
            
            && (TempString.find("FMJ", 0) == string::npos)
            && (TempString.substr(0, 12) != "DARKLING_CN_")
            && (TempString.find("DAYDREAMER_LAYTOREST", 0) == string::npos)
            && (TempString.substr(0, 23) != "OLDMANCARTER_WINDOW_2_B")
            && ((TempString.find("WINDOW", 0) != string::npos)
            || (TempString.find("LAYTOREST", 0) != string::npos)
            || (TempString.find("BANISH", 0) != string::npos))*/
            ) {

            checker = TempString[0];
            int CharacterCountTillFirstComma = 0;

            while (checker != ',') {
                checker = TempString[CharacterCountTillFirstComma];
                CharacterCountTillFirstComma++;
            }

            

            TempString = TempString.substr(0, CharacterCountTillFirstComma - 1);

            SpeechName[hashCount] = TempString;


            //cout << lalala << endl;

            stringstream ss;
            ss << hex << crc32(TempString.c_str());
            string Hash(ss.str());

            int CharacterCount = 0;

            checker = Hash[0];
            while (checker) //Turn lowercase chars into uppercase
            {
                checker = Hash[CharacterCount];
                if (islower(checker) != 1)
                {
                    Hash[CharacterCount] = toupper(checker);
                }

                CharacterCount++;
            }

            string ZeroString = "";

            for (int i = 0; i < (8 - (CharacterCount - 1)); i++)
            {
                ZeroString += '0';
            }

            Hash = ZeroString + Hash;


            char a = Hash[6];
            char b = Hash[7];
            char c = Hash[4];
            char d = Hash[5];
            char e = Hash[2];
            char f = Hash[3];
            char g = Hash[0];
            char h = Hash[1];

            Hash[0] = a;
            Hash[1] = b;
            Hash[2] = c;
            Hash[3] = d;
            Hash[4] = e;
            Hash[5] = f;
            Hash[6] = g;
            Hash[7] = h;


            

            vdDialogueHash_arr[hashCount] = Hash;
            //cout << vdDialogueHash_arr[hashCount] << endl;
            hashCount++;

        }
    }

    shuffle(SpeechName, SpeechName + hashCount, default_random_engine(seed + 69));

    return hashCount;

}

unsigned int __cdecl crc32bin(const char* byte, int ArrayLenght)
{
    unsigned int Hash;
    int i;
   
    Hash = 0;

    for (i = 0; i < ArrayLenght; ++i)
    {
        Hash = crc_table[(Hash >> 24) ^ (unsigned __int8)byte[i]] ^ (Hash << 8);
    }
    return ArrayLenght ^ Hash;
}

unsigned int __cdecl crc32(const char* String)
{
    return crc32bin(String, strlen(String));
}

void ClearSoundSubtitles(string* DialogueHash_arr, string* vdDialogueHash_arr, int vdDialogueCount, int DialogueCount)
{



    int u = 0;

    bool hashFound = false;

    while (u < DialogueCount)
    {
        int i = 0;
        
            hashFound = false;

            while (i < vdDialogueCount)
            {
                if (DialogueHash_arr[u] != "00000000")
                {
                    if (DialogueHash_arr[u] == vdDialogueHash_arr[i])
                    {
                        hashFound = true;
                        //cout << "Hash was found" << endl;
                        goto PerformCheck;
                    }
                }
                

                i++;
            }

        PerformCheck:
            if (hashFound == true)
            {
                DialogueHash_arr[u] = vdDialogueHash_arr[i];
            }

            else
            {
                DialogueHash_arr[u] = "00000000";
            }

            u++;
        
       
    }


}

int OutputSoundSubtitles(string ModsPath, string* DialogueHash_arr, int DialogueCount)
{
    ifstream asmIn(ModsPath + "SoundSubtitles.asm");
    ofstream asmOut(ModsPath + "SoundSubtitles.asm.Randomiser_TEMP");

    string TempString = "";

    int i = 0;


    while (TempString != "[ENABLE]")
    {
        getline(asmIn, TempString);
        if (TempString.substr(0, 2) == "db")
        {
            string Lalala = DialogueHash_arr[i];
            asmOut << "db " << Lalala[0] << Lalala[1] << " " << Lalala[2] << Lalala[3] << " "
                << Lalala[4] << Lalala[5] << " " << Lalala[6] << Lalala[7] << endl;
            i++;
        }
        else
        {
            asmOut << TempString << endl;
        }
            
        
    }

    while (asmIn)
    {
        getline(asmIn, TempString);
        asmOut << TempString << endl;
    }

    return i;

}



void GetSpecialHaunters(int* HasManifestPowerBaseKitArray, unsigned seed, int HaunterCount, int* SpecialHaunters, int* HaunterIDArray, string* HaunterFetterFlagStringArray, int* RemainingRestlessSpiritsIDArray)
{
    int j = 0;
    int TempArray[100]{};
    int TempArray2[100]{};

    for (int i = 0; i < HaunterCount; i++)
    {
        if (HasManifestPowerBaseKitArray[(HaunterIDArray[i])] == 1)
        {
            TempArray[j] = HaunterIDArray[i];
            j++;

        }
        
    }

    shuffle(TempArray, TempArray + j, default_random_engine(seed));

    SpecialHaunters[0] = TempArray[0];
    SpecialHaunters[1] = TempArray[1];
    SpecialHaunters[2] = TempArray[2];


    int u = 0;

    for (int i = 0; i < HaunterCount; i++)
    {
        if ((HaunterIDArray[i] != SpecialHaunters[0]) && (HaunterIDArray[i] != SpecialHaunters[1]) && (HaunterIDArray[i] != SpecialHaunters[2]))
        {
            TempArray[u] = HaunterIDArray[i];
            u++;
        }
    }

    u = 0;

    
    
    for (int i = 0; i < (HaunterCount - 3); i++)
    {
        int fetter_flags;
        stringstream ss;
        ss << hex << HaunterFetterFlagStringArray[(TempArray[i])];
        ss >> fetter_flags;

        if (fetter_flags & 8)
        {
            TempArray2[u] = TempArray[i];
            u++;
        }
    }

    shuffle(TempArray2, TempArray2 + u, default_random_engine(seed));


    SpecialHaunters[3] = TempArray2[0]; //fire


    u = 0;

    for (int i = 0; i < (HaunterCount - 3); i++)
    {
        if (TempArray[i] != SpecialHaunters[3])
        {
            TempArray2[u] = TempArray[i];
            u++;
        }
    }

    u = 0;

    for (int i = 0; i < (HaunterCount - 4); i++)
    {
        int fetter_flags;
        stringstream ss;
        ss << hex << HaunterFetterFlagStringArray[(TempArray2[i])];
        ss >> fetter_flags;

        if (fetter_flags & 64)
        {
            TempArray[u] = TempArray2[i];
            //cout << TempArray3[u] << " CHILD HAUNTER IDs" << endl;
            u++;
        }
    }

    shuffle(TempArray, TempArray + u, default_random_engine(seed));

    SpecialHaunters[4] = TempArray[0]; //child
    SpecialHaunters[5] = TempArray[1];
    u = 0;

    for (int i = 0; i < (HaunterCount - 4); i++)
    {
        if (TempArray2[i] != SpecialHaunters[4] && TempArray2[i] != SpecialHaunters[5])
        {
            TempArray[u] = TempArray2[i];
            //cout << RemainingRestlessSpiritsIDArray[u] << endl;
            u++;
        }
    }

    u = 0;
    for (int i = 0; i < (HaunterCount - 6); i++)
    {
        int fetter_flags;
        stringstream ss;
        ss << hex << HaunterFetterFlagStringArray[(TempArray[i])];
        ss >> fetter_flags;

        if (fetter_flags & 1)
        {
            TempArray2[u] = TempArray[i];
            //cout << TempArray3[u] << " CHILD HAUNTER IDs" << endl;
            u++;
        }
    }

    shuffle(TempArray2, TempArray2 + u, default_random_engine(seed));

    SpecialHaunters[6] = TempArray2[0];

    u = 0;


    for (int i = 0; i < (HaunterCount - 6); i++)
    {
        if (TempArray[i] != SpecialHaunters[6])
        {
            TempArray2[u] = TempArray[i];
            //cout << RemainingRestlessSpiritsIDArray[u] << endl;
            u++;
        }
    }

    u = 0;
    for (int i = 0; i < (HaunterCount - 7); i++)
    {
        int fetter_flags;
        stringstream ss;
        ss << hex << HaunterFetterFlagStringArray[(TempArray2[i])];
        ss >> fetter_flags;

        if (fetter_flags & 131072)
        {
            TempArray[u] = TempArray2[i];
            //cout << TempArray3[u] << " CHILD HAUNTER IDs" << endl;
            u++;
        }
    }

    shuffle(TempArray, TempArray + u, default_random_engine(seed));
    SpecialHaunters[7] = TempArray[0];
    u = 0;

    for (int i = 0; i < (HaunterCount - 7); i++)
    {
        if (TempArray2[i] != SpecialHaunters[7])
        {
            RemainingRestlessSpiritsIDArray[u] = TempArray2[i];
            //cout << RemainingRestlessSpiritsIDArray[u] << endl;
            u++;
        }
    }
}






void RandScenario_Haunting101(string ModsPath, string app_version, string* HaunterEnumArray, string* HaunterScriptInstanceArray, int* RemainingRestlessSpiritIDArray)
{
    ofstream OutputASM(ModsPath + "Random_Haunting101.asm");

    OutputASM << "//File generated by Leotachy's Ghost Master Randomiser " << app_version << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << "[ENABLE]" << endl;
    OutputASM << endl;
    OutputASM << "alloc(newmem,500)" << endl;
    OutputASM << endl;
    OutputASM << "label(ghostSI1)" << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << "newmem:" << endl;
    OutputASM << "ghostSI1:" << endl;
    OutputASM << "db " << HaunterScriptInstanceArray[(RemainingRestlessSpiritIDArray[0])] << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << "008DC7B8: " << endl;
    OutputASM << "dd ghostSI1" << endl;
    OutputASM << endl;
    OutputASM << "0053D158: " << endl;
    OutputASM << "push " << HaunterEnumArray[(RemainingRestlessSpiritIDArray[0])] << endl;
    OutputASM << endl;
    OutputASM << "0053D1A7: " << endl;
    OutputASM << "push ghostSI1" << endl;
    OutputASM << endl;
    OutputASM << "[DISABLE]" << endl;
    OutputASM << endl;
    OutputASM << "dealloc(newmem)" << endl;

    OutputASM.close();
}

void RandScenario_WeirdSeance(string ModsPath, string app_version, string* HaunterEnumArray, string* HaunterScriptInstanceArray, int* RemainingRestlessSpiritIDArray)
{
    ofstream OutputASM(ModsPath + "Random_WeirdSeance.asm");

    OutputASM << "//File generated by Leotachy's Ghost Master Randomiser " << app_version << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << "[ENABLE]" << endl;
    OutputASM << endl;
    OutputASM << "alloc(newmem,500)" << endl;
    OutputASM << endl;
    OutputASM << "label(ghostSI1)" << endl;
    OutputASM << "label(ghostSI2)" << endl;
    OutputASM << "label(ghostSI3)" << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << "newmem:" << endl;
    OutputASM << "ghostSI1:" << endl;
    OutputASM << "db " << HaunterScriptInstanceArray[(RemainingRestlessSpiritIDArray[1])] << endl;
    OutputASM << "ghostSI2:" << endl;
    OutputASM << "db " << HaunterScriptInstanceArray[(RemainingRestlessSpiritIDArray[2])] << endl;
    OutputASM << "ghostSI3:" << endl;
    OutputASM << "db " << HaunterScriptInstanceArray[(RemainingRestlessSpiritIDArray[3])] << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << "008E4308: " << endl;
    OutputASM << "dd ghostSI1" << endl;
    OutputASM << "005517E0: " << endl;
    OutputASM << "mov [008E4318]," << "ghostSI2" << endl;
    OutputASM << "005517EA: " << endl;
    OutputASM << "mov [008E4328]," << "ghostSI3" << endl;
    OutputASM << endl;

    OutputASM << "00554061: " << endl;
    OutputASM << "push " << HaunterEnumArray[(RemainingRestlessSpiritIDArray[1])] << endl;
    OutputASM << endl;
    OutputASM << "00554081: " << endl;
    OutputASM << "push ghostSI1" << endl;

    OutputASM << "00550231: " << endl;
    OutputASM << "push " << HaunterEnumArray[(RemainingRestlessSpiritIDArray[2])] << endl;
    OutputASM << endl;
    OutputASM << "00550298: " << endl;
    OutputASM << "push ghostSI2" << endl;

    OutputASM << "00554521: " << endl;
    OutputASM << "push " << HaunterEnumArray[(RemainingRestlessSpiritIDArray[3])] << endl;
    OutputASM << endl;
    OutputASM << "0055462C: " << endl;
    OutputASM << "push ghostSI3" << endl;



    OutputASM << endl;
    OutputASM << "[DISABLE]" << endl;
    OutputASM << endl;
    OutputASM << "dealloc(newmem)" << endl;

    OutputASM.close();
}

void RandScenario_Calamityville(string ModsPath, string app_version, string* HaunterEnumArray, string* HaunterScriptInstanceArray, int* RemainingRestlessSpiritIDArray)
{
    ofstream OutputASM(ModsPath + "Random_Calamityville.asm");

    OutputASM << "//File generated by Leotachy's Ghost Master Randomiser " << app_version << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << "[ENABLE]" << endl;
    OutputASM << endl;
    OutputASM << "alloc(newmem,500)" << endl;
    OutputASM << endl;
    OutputASM << "label(ghostSI1)" << endl;
    OutputASM << "label(ghostSI2)" << endl;
    OutputASM << "label(ghostSI3)" << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << "newmem:" << endl;
    OutputASM << "ghostSI1:" << endl;
    OutputASM << "db " << HaunterScriptInstanceArray[(RemainingRestlessSpiritIDArray[4])] << endl;
    OutputASM << "ghostSI2:" << endl;
    OutputASM << "db " << HaunterScriptInstanceArray[(RemainingRestlessSpiritIDArray[5])] << endl;
    OutputASM << "ghostSI3:" << endl;
    OutputASM << "db " << HaunterScriptInstanceArray[(RemainingRestlessSpiritIDArray[6])] << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << "008D5B90: " << endl;
    OutputASM << "dd ghostSI1" << endl;
    OutputASM << "00504120: " << endl;
    OutputASM << "mov [008D5BA0]," << "ghostSI2" << endl;
    OutputASM << "0050412A: " << endl;
    OutputASM << "mov [008D5BB0]," << "ghostSI3" << endl;
    OutputASM << endl;

    OutputASM << endl;
    OutputASM << "005124E1: " << endl;
    OutputASM << "push ghostSI1" << endl;

    OutputASM << "0050E08F: " << endl;
    OutputASM << "push " << HaunterEnumArray[(RemainingRestlessSpiritIDArray[4])] << endl;
    OutputASM << endl;
    OutputASM << "0050E0EE: " << endl;
    OutputASM << "push ghostSI2" << endl;

    OutputASM << endl;
    OutputASM << "0050FD52: " << endl;
    OutputASM << "push ghostSI3" << endl;



    OutputASM << endl;
    OutputASM << "[DISABLE]" << endl;
    OutputASM << endl;
    OutputASM << "dealloc(newmem)" << endl;

    OutputASM.close();
}

void RandScenario_Summoners(string ModsPath, string app_version, string* HaunterEnumArray, string* HaunterScriptInstanceArray, int* RemainingRestlessSpiritIDArray, int* SpecialHaunters)
{
    ofstream OutputASM(ModsPath + "Random_Summoners.asm");

    OutputASM << "//File generated by Leotachy's Ghost Master Randomiser " << app_version << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << "[ENABLE]" << endl;
    OutputASM << endl;
    OutputASM << "alloc(newmem,500)" << endl;
    OutputASM << endl;
    OutputASM << "label(ghostSI1)" << endl;
    OutputASM << "label(ghostSI2)" << endl;
    OutputASM << "label(ghostSI3)" << endl;
    OutputASM << "label(ghostSI4)" << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << "newmem:" << endl;
    OutputASM << "ghostSI1:" << endl;
    OutputASM << "db " << HaunterScriptInstanceArray[(RemainingRestlessSpiritIDArray[7])] << endl; //Darkling
    OutputASM << "ghostSI2:" << endl;
    OutputASM << "db " << HaunterScriptInstanceArray[(SpecialHaunters[0])] << endl;
    OutputASM << "ghostSI3:" << endl;
    OutputASM << "db " << HaunterScriptInstanceArray[(RemainingRestlessSpiritIDArray[8])] << endl;
    OutputASM << "ghostSI4:" << endl;
    OutputASM << "db " << HaunterScriptInstanceArray[(RemainingRestlessSpiritIDArray[9])] << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << "008D3D08: " << endl;
    OutputASM << "dd ghostSI1" << endl;
    OutputASM << "004F6383: " << endl;
    OutputASM << "mov [008D3D18]," << "ghostSI2" << endl;
    OutputASM << "mov [008D3D28]," << "ghostSI3" << endl;
    OutputASM << "mov [008D3D38]," << "ghostSI4" << endl;
    OutputASM << endl;

    OutputASM << "004F7B6E: " << endl;
    OutputASM << "push ghostSI1" << endl;
    OutputASM << "004FAAF1: " << endl;
    OutputASM << "push ghostSI1" << endl;
    OutputASM << endl;

    OutputASM << "004FBE18: " << endl;
    OutputASM << "push " << HaunterEnumArray[(SpecialHaunters[0])] << endl;
    OutputASM << "004FBE3D: " << endl;
    OutputASM << "push ghostSI2" << endl;
    OutputASM << "005027B3: " << endl;
    OutputASM << "push " << HaunterEnumArray[(SpecialHaunters[0])] << endl;
    OutputASM << "005027E4: " << endl;
    OutputASM << "push ghostSI2" << endl;
    OutputASM << endl;

    OutputASM << "004F84FF: " << endl;
    OutputASM << "push " << HaunterEnumArray[(RemainingRestlessSpiritIDArray[8])] << endl;
    OutputASM << "004F8518: " << endl;
    OutputASM << "push ghostSI3" << endl;

    OutputASM << endl;
    OutputASM << "004F80D7: " << endl;
    OutputASM << "push ghostSI4" << endl;
    OutputASM << "004F80E5: " << endl;
    OutputASM << "push ghostSI4" << endl;
    OutputASM << "00500DF8: " << endl;
    OutputASM << "push ghostSI4" << endl;
    OutputASM << "00500DB1: " << endl;
    OutputASM << "push " << HaunterEnumArray[(RemainingRestlessSpiritIDArray[9])] << endl;


    OutputASM << endl;
    OutputASM << "[DISABLE]" << endl;
    OutputASM << endl;
    OutputASM << "dealloc(newmem)" << endl;

    OutputASM.close();
}

void RandScenario_Deadfellas(string ModsPath, string app_version, string* HaunterEnumArray, string* HaunterScriptInstanceArray, int* RemainingRestlessSpiritIDArray)
{
    ofstream OutputASM(ModsPath + "Random_Deadfellas.asm");

    OutputASM << "//File generated by Leotachy's Ghost Master Randomiser " << app_version << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << "[ENABLE]" << endl;
    OutputASM << endl;
    OutputASM << "alloc(newmem,500)" << endl;
    OutputASM << endl;
    OutputASM << "label(ghostSI1)" << endl;
    OutputASM << "label(ghostSI2)" << endl;
    OutputASM << "label(ghostSI3)" << endl;
    OutputASM << "label(ghostSI4)" << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << "newmem:" << endl;
    OutputASM << "ghostSI1:" << endl;
    OutputASM << "db " << HaunterScriptInstanceArray[(RemainingRestlessSpiritIDArray[10])] << endl;
    OutputASM << "ghostSI2:" << endl;
    OutputASM << "db " << HaunterScriptInstanceArray[(RemainingRestlessSpiritIDArray[11])] << endl;
    OutputASM << "ghostSI3:" << endl;
    OutputASM << "db " << HaunterScriptInstanceArray[(RemainingRestlessSpiritIDArray[12])] << endl;
    OutputASM << "ghostSI4:" << endl;
    OutputASM << "db " << HaunterScriptInstanceArray[(RemainingRestlessSpiritIDArray[13])] << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << "008D8408: " << endl;
    OutputASM << "dd ghostSI1" << endl;
    OutputASM << "00514E62: " << endl;
    OutputASM << "mov [008D8418]," << "ghostSI2" << endl;
    OutputASM << "mov [008D8428]," << "ghostSI3" << endl;
    OutputASM << "mov [008D8438]," << "ghostSI4" << endl;
    OutputASM << endl;

    OutputASM << "00518443: " << endl;
    OutputASM << "push ghostSI1" << endl;
    OutputASM << "00518C6A: " << endl;
    OutputASM << "push ghostSI1" << endl;
    OutputASM << "00518C1A: " << endl;
    OutputASM << "push " << HaunterEnumArray[(RemainingRestlessSpiritIDArray[10])] << endl;

    OutputASM << "00519967: " << endl;
    OutputASM << "push ghostSI2" << endl;
    OutputASM << "00519F51: " << endl;
    OutputASM << "push " << HaunterEnumArray[(RemainingRestlessSpiritIDArray[11])] << endl;
    OutputASM << "00519F86: " << endl;
    OutputASM << "push ghostSI2" << endl;
    OutputASM << endl;

    OutputASM << "0051A25A: " << endl;
    OutputASM << "push " << HaunterEnumArray[(RemainingRestlessSpiritIDArray[12])] << endl;
    OutputASM << "0051A277: " << endl;
    OutputASM << "push ghostSI3" << endl;

    OutputASM << endl;
    OutputASM << "0051A98A: " << endl;
    OutputASM << "push ghostSI4" << endl;
    OutputASM << "0051A977: " << endl;
    OutputASM << "push " << HaunterEnumArray[(RemainingRestlessSpiritIDArray[13])] << endl;


    OutputASM << endl;
    OutputASM << "[DISABLE]" << endl;
    OutputASM << endl;
    OutputASM << "dealloc(newmem)" << endl;

    OutputASM.close();
}

void RandScenario_Facepacks(string ModsPath, string app_version, string* HaunterEnumArray, string* HaunterScriptInstanceArray, int* RemainingRestlessSpiritIDArray, int* SpecialHaunters)
{
    ofstream OutputASM(ModsPath + "Random_Facepacks.asm");

    OutputASM << "//File generated by Leotachy's Ghost Master Randomiser " << app_version << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << "[ENABLE]" << endl;
    OutputASM << endl;
    OutputASM << "alloc(newmem,500)" << endl;
    OutputASM << endl;
    OutputASM << "label(ghostSI1)" << endl;
    OutputASM << "label(ghostSI2)" << endl;
    OutputASM << "label(ghostSI3)" << endl;
    OutputASM << "label(ghostSI4)" << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << "newmem:" << endl;
    OutputASM << "ghostSI1:" << endl;
    OutputASM << "db " << HaunterScriptInstanceArray[(SpecialHaunters[3])] << endl;
    OutputASM << "ghostSI2:" << endl;
    OutputASM << "db " << HaunterScriptInstanceArray[(RemainingRestlessSpiritIDArray[14])] << endl;
    OutputASM << "ghostSI3:" << endl;
    OutputASM << "db " << HaunterScriptInstanceArray[(SpecialHaunters[6])] << endl;
    OutputASM << "ghostSI4:" << endl;
    OutputASM << "db " << HaunterScriptInstanceArray[(RemainingRestlessSpiritIDArray[0])] << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << "008DF118: " << endl;
    OutputASM << "dd ghostSI1" << endl;
    OutputASM << "0053BD12: " << endl;
    OutputASM << "mov [008DF128]," << "ghostSI2" << endl; //mirage
    OutputASM << "mov [008DF138]," << "ghostSI3" << endl; //hogwash
    OutputASM << "mov [008DF148]," << "ghostSI4" << endl; //weatherwitch
    OutputASM << endl;

    OutputASM << "00535651: " << endl;
    OutputASM << "push " << HaunterEnumArray[(SpecialHaunters[3])] << endl;
    OutputASM << "00535670: " << endl;
    OutputASM << "push ghostSI1" << endl;
    OutputASM << "005386EE: " << endl;
    OutputASM << "push " << HaunterEnumArray[(SpecialHaunters[3])] << endl;
    OutputASM << "0053871C: " << endl;
    OutputASM << "push ghostSI1" << endl;
    OutputASM << "00538B25: " << endl;
    OutputASM << "push ghostSI1" << endl;

    OutputASM << "00536568: " << endl;
    OutputASM << "push ghostSI2" << endl;
    OutputASM << "0053654A: " << endl;
    OutputASM << "push " << HaunterEnumArray[(RemainingRestlessSpiritIDArray[14])] << endl;

    OutputASM << "00535780: " << endl;
    OutputASM << "push ghostSI3" << endl;
    OutputASM << "00535761: " << endl;
    OutputASM << "push " << HaunterEnumArray[(SpecialHaunters[6])] << endl;

    


    OutputASM << endl;
    OutputASM << "[DISABLE]" << endl;
    OutputASM << endl;
    OutputASM << "dealloc(newmem)" << endl;

    OutputASM.close();
}

void RandScenario_Unusual(string ModsPath, string app_version, string* HaunterEnumArray, string* HaunterScriptInstanceArray, int* RemainingRestlessSpiritIDArray)
{
    ofstream OutputASM(ModsPath + "Random_Unusual.asm");

    OutputASM << "//File generated by Leotachy's Ghost Master Randomiser " << app_version << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << "[ENABLE]" << endl;
    OutputASM << endl;
    OutputASM << "alloc(newmem,500)" << endl;
    OutputASM << endl;
    OutputASM << "label(ghostSI1)" << endl;
    OutputASM << "label(ghostSI2)" << endl;
    OutputASM << "label(ghostSI3)" << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << "newmem:" << endl;
    OutputASM << "ghostSI1:" << endl;
    OutputASM << "db " << HaunterScriptInstanceArray[(RemainingRestlessSpiritIDArray[15])] << endl;
    OutputASM << "ghostSI2:" << endl;
    OutputASM << "db " << HaunterScriptInstanceArray[(RemainingRestlessSpiritIDArray[16])] << endl;
    OutputASM << "ghostSI3:" << endl;
    OutputASM << "db " << HaunterScriptInstanceArray[(RemainingRestlessSpiritIDArray[17])] << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << "008DB368: " << endl;
    OutputASM << "dd ghostSI1" << endl;
    OutputASM << "0052D751: " << endl;
    OutputASM << "mov [008DB378]," << "ghostSI2" << endl; 
    OutputASM << "mov [008DB388]," << "ghostSI3" << endl; 
    OutputASM << endl;

    OutputASM << "00529226: " << endl;
    OutputASM << "push ghostSI1" << endl;
    OutputASM << "005293E0: " << endl;
    OutputASM << "push ghostSI1" << endl;

    OutputASM << "00527391: " << endl;
    OutputASM << "push ghostSI2" << endl;
    OutputASM << "00527324: " << endl;
    OutputASM << "push " << HaunterEnumArray[(RemainingRestlessSpiritIDArray[17])] << endl;

    OutputASM << "0052F510: " << endl;
    OutputASM << "push ghostSI3" << endl;
    OutputASM << "0052F4F1: " << endl;
    OutputASM << "push " << HaunterEnumArray[(RemainingRestlessSpiritIDArray[18])] << endl;




    OutputASM << endl;
    OutputASM << "[DISABLE]" << endl;
    OutputASM << endl;
    OutputASM << "dealloc(newmem)" << endl;

    OutputASM.close();
}

void RandScenario_Poultrygeist(string ModsPath, string app_version, string* HaunterEnumArray, string* HaunterScriptInstanceArray, int* RemainingRestlessSpiritIDArray, int* SpecialHaunters)
{
    ofstream OutputASM(ModsPath + "Random_Poultrygeist.asm");

    OutputASM << "//File generated by Leotachy's Ghost Master Randomiser " << app_version << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << "[ENABLE]" << endl;
    OutputASM << endl;
    OutputASM << "alloc(newmem,500)" << endl;
    OutputASM << endl;
    OutputASM << "label(ghostSI1)" << endl;
    OutputASM << "label(ghostSI2)" << endl;
    OutputASM << "label(ghostSI3)" << endl;
    OutputASM << "label(ghostSI4)" << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << "newmem:" << endl;
    OutputASM << "ghostSI1:" << endl;
    OutputASM << "db " << HaunterScriptInstanceArray[(RemainingRestlessSpiritIDArray[4])] << endl;
    OutputASM << "ghostSI2:" << endl;
    OutputASM << "db " << HaunterScriptInstanceArray[(RemainingRestlessSpiritIDArray[5])] << endl;
    OutputASM << "ghostSI3:" << endl;
    OutputASM << "db " << HaunterScriptInstanceArray[(RemainingRestlessSpiritIDArray[6])] << endl;
    OutputASM << "ghostSI4:" << endl;
    OutputASM << "db " << HaunterScriptInstanceArray[(SpecialHaunters[4])] << endl;
    OutputASM << endl;

    OutputASM << endl;
    OutputASM << "008D65F8: " << endl;
    OutputASM << "dd ghostSI1" << endl;
    OutputASM << "00509E27: " << endl;
    OutputASM << "mov [008D6608]," << "ghostSI2" << endl;
    OutputASM << "mov [008D6618]," << "ghostSI3" << endl;
    OutputASM << "00509E41: " << endl;
    OutputASM << "mov [008D6628]," << "ghostSI4" << endl;
    OutputASM << endl;

    OutputASM << "0050A10F: " << endl;
    OutputASM << "push ghostSI4" << endl;
    OutputASM << "0050A193: " << endl;
    OutputASM << "push ghostSI4" << endl;
    OutputASM << "0050A182: " << endl;
    OutputASM << "push " << HaunterEnumArray[(SpecialHaunters[4])] << endl;




    OutputASM << endl;
    OutputASM << "[DISABLE]" << endl;
    OutputASM << endl;
    OutputASM << "dealloc(newmem)" << endl;

    OutputASM.close();
}

void RandScenario_Phantom(string ModsPath, string app_version, string* HaunterEnumArray, string* HaunterScriptInstanceArray, int* RemainingRestlessSpiritIDArray, int* SpecialHaunters)
{
    ofstream OutputASM(ModsPath + "Random_Phantom.asm");

    OutputASM << "//File generated by Leotachy's Ghost Master Randomiser " << app_version << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << "[ENABLE]" << endl;
    OutputASM << endl;
    OutputASM << "alloc(newmem,500)" << endl;
    OutputASM << endl;
    OutputASM << "label(ghostSI1)" << endl;
    OutputASM << "label(ghostSI2)" << endl;
    OutputASM << "label(ghostSI3)" << endl;
    OutputASM << "label(CrashFix)" << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << "newmem:" << endl;
    OutputASM << "ghostSI1:" << endl;
    OutputASM << "db " << HaunterScriptInstanceArray[(SpecialHaunters[1])] << endl;
    OutputASM << "ghostSI2:" << endl;
    OutputASM << "db " << HaunterScriptInstanceArray[(SpecialHaunters[5])] << endl;
    OutputASM << "ghostSI3:" << endl;
    OutputASM << "db " << HaunterScriptInstanceArray[(RemainingRestlessSpiritIDArray[18])] << endl;
    OutputASM << "CrashFix:" << endl;
    OutputASM << "call 007ED8E0" << endl;
    OutputASM << "test eax,eax" << endl;
    OutputASM << "jne 006D4791" << endl;
    OutputASM << "push 00909108" << endl;
    OutputASM << "jmp 006D4781" << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << "008CF1D0: " << endl;
    OutputASM << "dd ghostSI1" << endl;
    OutputASM << "004DE601: " << endl;
    OutputASM << "mov [008CF1E0]," << "ghostSI2" << endl;
    //OutputASM << "mov [008CF1E8],00000000" << endl; //Unlink Harriet
    OutputASM << "004DE615: " << endl;
    OutputASM << "mov [008CF1F0]," << "ghostSI3" << endl;

    OutputASM << endl;

    OutputASM << "004E045A: " << endl;
    OutputASM << "push ghostSI1" << endl;
    OutputASM << "004E0431: " << endl;
    OutputASM << "push " << HaunterEnumArray[(SpecialHaunters[1])] << endl;


    OutputASM << "004E1E00: " << endl;
    OutputASM << "push ghostSI2" << endl;
    OutputASM << "004E1DE1: " << endl;
    OutputASM << "push " << HaunterEnumArray[(SpecialHaunters[5])] << endl;

    OutputASM << "004E0BDD: " << endl;
    OutputASM << "push ghostSI3" << endl;
    OutputASM << "004E0BB1: " << endl;
    OutputASM << "push " << HaunterEnumArray[(RemainingRestlessSpiritIDArray[19])] << endl;


    //DAYDREAMER PARTICLE FIX
    OutputASM << "006D478C: " << endl;
    OutputASM << "jmp CrashFix" << endl;
    OutputASM << endl;




    OutputASM << endl;
    OutputASM << "[DISABLE]" << endl;
    OutputASM << endl;
    OutputASM << "006D478C: " << endl;
    OutputASM << "call 007ED8E0" << endl;
    OutputASM << "dealloc(newmem)" << endl;

    OutputASM.close();
}

void RandScenario_Wisp(string ModsPath, string app_version, string* HaunterEnumArray, string* HaunterScriptInstanceArray, int* RemainingRestlessSpiritIDArray, int* SpecialHaunters)
{
    ofstream OutputASM(ModsPath + "Random_Wisp.asm");

    OutputASM << "//File generated by Leotachy's Ghost Master Randomiser " << app_version << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << "[ENABLE]" << endl;
    OutputASM << endl;
    OutputASM << "alloc(newmem,500)" << endl;
    OutputASM << endl;
    OutputASM << "label(ghostSI1)" << endl;
    OutputASM << "label(ghostSI2)" << endl;
    OutputASM << "label(ghostSI3)" << endl;
    OutputASM << "label(ghostSI4)" << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << "newmem:" << endl;
    OutputASM << "ghostSI1:" << endl;
    OutputASM << "db " << HaunterScriptInstanceArray[(SpecialHaunters[0])] << endl;
    OutputASM << "ghostSI2:" << endl;
    OutputASM << "db " << HaunterScriptInstanceArray[(RemainingRestlessSpiritIDArray[7])] << endl;
    OutputASM << "ghostSI3:" << endl;
    OutputASM << "db " << HaunterScriptInstanceArray[(RemainingRestlessSpiritIDArray[19])] << endl;
    OutputASM << "ghostSI4:" << endl;
    OutputASM << "db " << HaunterScriptInstanceArray[(SpecialHaunters[2])] << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << "008D2210: " << endl;
    OutputASM << "dd ghostSI1" << endl;
    OutputASM << "004E9512: " << endl;
    OutputASM << "mov [008D2220]," << "ghostSI2" << endl; //darkling
    OutputASM << "mov [008D2230]," << "ghostSI3" << endl; //sparkle
    OutputASM << "mov [008D2240]," << "ghostSI4" << endl; //wisp
    OutputASM << endl;

    OutputASM << "004F4431: " << endl;
    OutputASM << "push ghostSI2" << endl;


    OutputASM << "004F24DA: " << endl;
    OutputASM << "push ghostSI3" << endl;
    OutputASM << "004F2DC0: " << endl;
    OutputASM << "push ghostSI3" << endl;
    OutputASM << "004F2DA1: " << endl;
    OutputASM << "push " << HaunterEnumArray[(RemainingRestlessSpiritIDArray[20])] << endl;

    OutputASM << "004EFABC: " << endl;
    OutputASM << "push ghostSI4" << endl;
    OutputASM << "004EFA9E: " << endl;
    OutputASM << "push " << HaunterEnumArray[(SpecialHaunters[2])] << endl;




    OutputASM << endl;
    OutputASM << "[DISABLE]" << endl;
    OutputASM << endl;
    OutputASM << "dealloc(newmem)" << endl;

    OutputASM.close();
}

void RandScenario_Spooky(string ModsPath, string app_version, string* HaunterEnumArray, string* HaunterScriptInstanceArray, int* RemainingRestlessSpiritIDArray, int* SpecialHaunters)
{
    ofstream OutputASM(ModsPath + "Random_Spooky.asm");

    OutputASM << "//File generated by Leotachy's Ghost Master Randomiser " << app_version << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << "[ENABLE]" << endl;
    OutputASM << endl;
    OutputASM << "alloc(newmem,500)" << endl;
    OutputASM << endl;
    OutputASM << "label(ghostSI1)" << endl;
    OutputASM << "label(ghostSI2)" << endl;
    OutputASM << "label(ghostSI3)" << endl;
    OutputASM << "label(ghostSI4)" << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << "newmem:" << endl;
    OutputASM << "ghostSI1:" << endl;
    OutputASM << "db " << HaunterScriptInstanceArray[(SpecialHaunters[7])] << endl;
    OutputASM << "ghostSI2:" << endl;
    OutputASM << "db " << HaunterScriptInstanceArray[(RemainingRestlessSpiritIDArray[20])] << endl;
    OutputASM << "ghostSI3:" << endl;
    OutputASM << "db " << HaunterScriptInstanceArray[(RemainingRestlessSpiritIDArray[21])] << endl;
    OutputASM << "ghostSI4:" << endl;
    OutputASM << "db " << HaunterScriptInstanceArray[(RemainingRestlessSpiritIDArray[22])] << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << "008E0318: " << endl;
    OutputASM << "dd ghostSI1" << endl;
    OutputASM << "00548753: " << endl;
    OutputASM << "mov [008E0328]," << "ghostSI2" << endl;
    OutputASM << "mov [008E0338]," << "ghostSI3" << endl;
    OutputASM << "mov [008E0348]," << "ghostSI4" << endl;
    OutputASM << endl;

    OutputASM << "00544DE1: " << endl;
    OutputASM << "push ghostSI1" << endl;
    OutputASM << "0054AA37: " << endl;
    OutputASM << "push ghostSI1" << endl;

    OutputASM << "0054AAA8: " << endl;
    OutputASM << "push ghostSI2" << endl;
    OutputASM << endl;

    OutputASM << "0054AA75: " << endl;
    OutputASM << "push ghostSI3" << endl;
    OutputASM << endl;

    OutputASM << "0054AADB: " << endl;
    OutputASM << "push ghostSI4" << endl;
    OutputASM << endl;

    OutputASM << "[DISABLE]" << endl;
    OutputASM << endl;
    OutputASM << "dealloc(newmem)" << endl;

    OutputASM.close();
}

void RandScenario_Ghostbreakers(string ModsPath, string app_version, string* HaunterEnumArray, string* HaunterScriptInstanceArray, int* RemainingRestlessSpiritIDArray)
{
    ofstream OutputASM(ModsPath + "Random_Ghostbreakers.asm");

    OutputASM << "//File generated by Leotachy's Ghost Master Randomiser " << app_version << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << "[ENABLE]" << endl;
    OutputASM << endl;
    OutputASM << "alloc(newmem,500)" << endl;
    OutputASM << endl;
    OutputASM << "label(ghostSI1)" << endl;
    OutputASM << "label(ghostSI2)" << endl;
    OutputASM << "label(ghostSI3)" << endl;
    OutputASM << "label(ghostSI4)" << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << "newmem:" << endl;
    OutputASM << "ghostSI1:" << endl;
    OutputASM << "db " << HaunterScriptInstanceArray[(RemainingRestlessSpiritIDArray[15])] << endl;
    OutputASM << "ghostSI2:" << endl;
    OutputASM << "db " << HaunterScriptInstanceArray[(RemainingRestlessSpiritIDArray[16])] << endl;
    OutputASM << "ghostSI3:" << endl;
    OutputASM << "db " << HaunterScriptInstanceArray[(RemainingRestlessSpiritIDArray[17])] << endl;
    OutputASM << "ghostSI4:" << endl;
    OutputASM << "db " << HaunterScriptInstanceArray[(RemainingRestlessSpiritIDArray[23])] << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << "008D9DD8: " << endl;
    OutputASM << "dd ghostSI1" << endl;
    OutputASM << "008D9DE8: " << endl;
    OutputASM << "dd ghostSI2" << endl;
    OutputASM << "008D9DF8: " << endl;
    OutputASM << "dd ghostSI3" << endl;
    OutputASM << "008D9E08: " << endl;
    OutputASM << "dd ghostSI4" << endl;
    OutputASM << endl;

    OutputASM << "0051E900: " << endl;
    OutputASM << "push ghostSI1" << endl;

    OutputASM << "0051E90A: " << endl;
    OutputASM << "push ghostSI2" << endl;

    OutputASM << "0051E919: " << endl;
    OutputASM << "push ghostSI3" << endl;

    OutputASM << "0051E928: " << endl;
    OutputASM << "push ghostSI4" << endl;

    OutputASM << "[DISABLE]" << endl;
    OutputASM << endl;
    OutputASM << "dealloc(newmem)" << endl;

    OutputASM.close();
}

void RandScenario_MortalJacket(string ModsPath, string app_version, string* HaunterEnumArray, string* HaunterScriptInstanceArray, int* RemainingRestlessSpiritIDArray)
{
    ofstream OutputASM(ModsPath + "Random_MortalJacket.asm");

    OutputASM << "//File generated by Leotachy's Ghost Master Randomiser " << app_version << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << "[ENABLE]" << endl;
    OutputASM << endl;
    OutputASM << "alloc(newmem,500)" << endl;
    OutputASM << endl;
    OutputASM << "label(ghostSI1)" << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << "newmem:" << endl;
    OutputASM << "ghostSI1:" << endl;
    OutputASM << "db " << HaunterScriptInstanceArray[(RemainingRestlessSpiritIDArray[24])] << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << "008CC220: " << endl;
    OutputASM << "dd ghostSI1" << endl;
    OutputASM << endl;

    OutputASM << "004D0347: " << endl;
    OutputASM << "push ghostSI1" << endl;


    OutputASM << "[DISABLE]" << endl;
    OutputASM << endl;
    OutputASM << "dealloc(newmem)" << endl;

    OutputASM.close();
}

void RandScenario_Cuckoos(string ModsPath, string app_version, string* HaunterEnumArray, string* HaunterScriptInstanceArray, int* RemainingRestlessSpiritIDArray)
{
    ofstream OutputASM(ModsPath + "Random_Cuckoos.asm");

    OutputASM << "//File generated by Leotachy's Ghost Master Randomiser " << app_version << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << "[ENABLE]" << endl;
    OutputASM << endl;
    OutputASM << "alloc(newmem,500)" << endl;
    OutputASM << endl;
    OutputASM << "label(ghostSI1)" << endl;
    OutputASM << "label(ghostSI2)" << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << "newmem:" << endl;
    OutputASM << "ghostSI1:" << endl;
    OutputASM << "db " << HaunterScriptInstanceArray[(RemainingRestlessSpiritIDArray[18])] << endl;
    OutputASM << "ghostSI2:" << endl;
    OutputASM << "db " << HaunterScriptInstanceArray[(RemainingRestlessSpiritIDArray[7])] << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << "008CDB68: " << endl;
    OutputASM << "dd ghostSI1" << endl;
    OutputASM << "004D741E: " << endl;
    OutputASM << "mov [008CDB78]," << "ghostSI2" << endl;
    OutputASM << endl;

    OutputASM << "004DA953: " << endl;
    OutputASM << "push ghostSI2" << endl;
    OutputASM << "004DA942: " << endl;
    OutputASM << "push " << HaunterEnumArray[(RemainingRestlessSpiritIDArray[7])] << endl;
    OutputASM << "004DB465: " << endl;
    OutputASM << "push " << HaunterEnumArray[(RemainingRestlessSpiritIDArray[7])] << endl;


    OutputASM << "[DISABLE]" << endl;
    OutputASM << endl;
    OutputASM << "dealloc(newmem)" << endl;

    OutputASM.close();
}


void OutputScenarioOrder(string ModsPath, string app_version, string* Sc_Available_Array, string* Sc_Completed_Array, string* Sc_Name_Array, string* Sc_ScriptInstance_Array, int* ScenarioIndexes)
{
    ofstream OutputASM(ModsPath + "Random_ScenarioOrder.asm");


    OutputASM << "//File generated by Leotachy's Ghost Master Randomiser " << app_version << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << "[ENABLE]" << endl;
    OutputASM << endl;
    OutputASM << "004A8BC6: " << endl;
    OutputASM << "mov ecx, [" << Sc_Completed_Array[ScenarioIndexes[0]] << "]" << endl;
    OutputASM << "004A8BE6: " << endl;
    OutputASM << "mov [" << Sc_Available_Array[0] << "], eax" << endl;
    OutputASM << "004A8BF7: " << endl;
    OutputASM << "mov ecx, [" << Sc_Completed_Array[ScenarioIndexes[1]] << "]" << endl;
    OutputASM << "mov [" << Sc_Available_Array[1] << "], eax" << endl;
    OutputASM << "004A8C04: " << endl;
    OutputASM << "mov [" << Sc_Available_Array[2] << "], eax" << endl;
    OutputASM << "004A8C14: " << endl;
    OutputASM << "mov ecx, [" << Sc_Completed_Array[ScenarioIndexes[2]] << "]" << endl;
    OutputASM << "004A8C22: " << endl;
    OutputASM << "mov ecx, [" << Sc_Completed_Array[ScenarioIndexes[3]] << "]" << endl;
    OutputASM << "mov [" << Sc_Available_Array[3] << "], eax" << endl;
    OutputASM << "004A8C35: " << endl;
    OutputASM << "mov esi, [" << Sc_Completed_Array[ScenarioIndexes[4]] << "]" << endl;
    OutputASM << "004A8C45: " << endl;
    OutputASM << "mov [" << Sc_Available_Array[4] << "], eax" << endl;
    OutputASM << "mov [" << Sc_Available_Array[5] << "], eax" << endl;
    OutputASM << "004A8C51: " << endl;
    OutputASM << "mov [" << Sc_Available_Array[6] << "], eax" << endl;
    OutputASM << "004A8C56: " << endl;
    OutputASM << "mov edi, [" << Sc_Completed_Array[ScenarioIndexes[5]] << "]" << endl;
    OutputASM << "mov ecx, [" << Sc_Completed_Array[ScenarioIndexes[7]] << "]" << endl;
    OutputASM << "004A8C68: " << endl;
    OutputASM << "mov [" << Sc_Available_Array[7] << "], eax" << endl;
    OutputASM << "004A8C6F: " << endl;
    OutputASM << "mov [" << Sc_Available_Array[8] << "], eax" << endl;
    OutputASM << "004A8C7C: " << endl;
    OutputASM << "mov esi, [" << Sc_Completed_Array[ScenarioIndexes[6]] << "]" << endl;
    OutputASM << "004A8C9A: " << endl;
    OutputASM << "mov ecx, [" << Sc_Completed_Array[ScenarioIndexes[8]] << "]" << endl;
    OutputASM << "004A8CA4: " << endl;
    OutputASM << "mov ecx, [" << Sc_Completed_Array[ScenarioIndexes[9]] << "]" << endl;
    OutputASM << "mov [" << Sc_Available_Array[9] << "], eax" << endl;
    OutputASM << "004A8CB3: " << endl;
    OutputASM << "mov ecx, [" << Sc_Completed_Array[ScenarioIndexes[11]] << "]" << endl;
    OutputASM << "004A8CC6: " << endl;
    OutputASM << "mov [" << Sc_Available_Array[10] << "], eax" << endl;
    OutputASM << "mov [" << Sc_Available_Array[11] << "], eax" << endl;
    OutputASM << "004A8CD2: " << endl;
    OutputASM << "mov [" << Sc_Available_Array[12] << "], eax" << endl;
    OutputASM << "004A8CD7: " << endl;
    OutputASM << "mov esi, [" << Sc_Completed_Array[ScenarioIndexes[10]] << "]" << endl;
    OutputASM << "004A8CE5: " << endl;
    OutputASM << "mov ecx, [" << Sc_Completed_Array[ScenarioIndexes[12]] << "]" << endl;
    OutputASM << "004A8CEF: " << endl;
    OutputASM << "mov ecx, [" << Sc_Completed_Array[ScenarioIndexes[13]] << "]" << endl;
    OutputASM << "mov [" << Sc_Available_Array[13] << "], eax" << endl;
    OutputASM << "004A8CFE: " << endl;
    OutputASM << "mov [" << Sc_Available_Array[14] << "], eax" << endl;
    OutputASM << "mov eax, [" << Sc_Completed_Array[ScenarioIndexes[14]] << "]" << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << "004A7E31: " << endl;
    OutputASM << "mov eax, [" << Sc_Completed_Array[ScenarioIndexes[3]] << "]" << endl;
    OutputASM << "004A7E3E: " << endl;
    OutputASM << "mov esi," << Sc_ScriptInstance_Array[ScenarioIndexes[3]] << endl;
    OutputASM << "004A7E54: " << endl;
    OutputASM << "mov eax, [" << Sc_Completed_Array[ScenarioIndexes[9]] << "]" << endl;
    OutputASM << "004A7E61: " << endl;
    OutputASM << "mov esi," << Sc_ScriptInstance_Array[ScenarioIndexes[9]] << endl;
    OutputASM << "004A7E77: " << endl;
    OutputASM << "mov eax, [" << Sc_Completed_Array[ScenarioIndexes[12]] << "]" << endl;
    OutputASM << "004A7E84: " << endl;
    OutputASM << "mov esi," << Sc_ScriptInstance_Array[ScenarioIndexes[12]] << endl;
    OutputASM << "004A7E9A: " << endl;
    OutputASM << "mov eax, [" << Sc_Completed_Array[ScenarioIndexes[10]] << "]" << endl;
    OutputASM << "004A7EA7: " << endl;
    OutputASM << "mov esi," << Sc_ScriptInstance_Array[ScenarioIndexes[10]] << endl;
    OutputASM << "004A7EB9: " << endl;
    OutputASM << "mov eax, [" << Sc_Completed_Array[ScenarioIndexes[7]] << "]" << endl;
    OutputASM << "004A7EC2: " << endl;
    OutputASM << "mov esi," << Sc_ScriptInstance_Array[ScenarioIndexes[7]] << endl;
    OutputASM << "004A7ED8: " << endl;
    OutputASM << "mov eax, [" << Sc_Completed_Array[ScenarioIndexes[0]] << "]" << endl;
    OutputASM << "004A7EE5: " << endl;
    OutputASM << "mov esi," << Sc_ScriptInstance_Array[ScenarioIndexes[0]] << endl;
    OutputASM << "004A7EF7: " << endl;
    OutputASM << "mov eax, [" << Sc_Completed_Array[ScenarioIndexes[11]] << "]" << endl;
    OutputASM << "004A7F00: " << endl;
    OutputASM << "mov esi," << Sc_ScriptInstance_Array[ScenarioIndexes[11]] << endl;
    OutputASM << "004A7F16: " << endl;
    OutputASM << "mov eax, [" << Sc_Completed_Array[ScenarioIndexes[5]] << "]" << endl;
    OutputASM << "004A7F23: " << endl;
    OutputASM << "mov esi," << Sc_ScriptInstance_Array[ScenarioIndexes[5]] << endl;
    OutputASM << "004A7F35: " << endl;
    OutputASM << "mov eax, [" << Sc_Completed_Array[ScenarioIndexes[6]] << "]" << endl;
    OutputASM << "004A7F3E: " << endl;
    OutputASM << "mov esi," << Sc_ScriptInstance_Array[ScenarioIndexes[6]] << endl;
    OutputASM << "004A7F54: " << endl;
    OutputASM << "mov eax, [" << Sc_Completed_Array[ScenarioIndexes[2]] << "]" << endl;
    OutputASM << "004A7F61: " << endl;
    OutputASM << "mov esi," << Sc_ScriptInstance_Array[ScenarioIndexes[2]] << endl;
    OutputASM << "004A7F77: " << endl;
    OutputASM << "mov eax, [" << Sc_Completed_Array[ScenarioIndexes[1]] << "]" << endl;
    OutputASM << "004A7F80: " << endl;
    OutputASM << "mov esi," << Sc_ScriptInstance_Array[ScenarioIndexes[1]] << endl;
    OutputASM << "004A7F92: " << endl;
    OutputASM << "mov eax, [" << Sc_Completed_Array[ScenarioIndexes[13]] << "]" << endl;
    OutputASM << "004A7F9B: " << endl;
    OutputASM << "mov esi," << Sc_ScriptInstance_Array[ScenarioIndexes[13]] << endl;
    OutputASM << "004A7FAD: " << endl;
    OutputASM << "mov eax, [" << Sc_Completed_Array[ScenarioIndexes[8]] << "]" << endl;
    OutputASM << "004A7FB6: " << endl;
    OutputASM << "mov esi," << Sc_ScriptInstance_Array[ScenarioIndexes[8]] << endl;
    OutputASM << "004A7FC8: " << endl;
    OutputASM << "mov eax, [" << Sc_Completed_Array[ScenarioIndexes[4]] << "]" << endl;
    OutputASM << "004A7FD1: " << endl;
    OutputASM << "mov esi," << Sc_ScriptInstance_Array[ScenarioIndexes[4]] << endl;
    OutputASM << "004A7FF5: " << endl;
    OutputASM << "mov esi," << Sc_ScriptInstance_Array[ScenarioIndexes[14]] << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << endl;
    //Highscares order
    OutputASM << "00455452: " << endl;
    OutputASM << "mov [esp+2C]," << Sc_Name_Array[ScenarioIndexes[0]] << endl;
    OutputASM << "00455477: " << endl;
    OutputASM << "mov [esp+30]," << Sc_Name_Array[ScenarioIndexes[1]] << endl;
    OutputASM << "00455496: " << endl;
    OutputASM << "mov [esp+30]," << Sc_Name_Array[ScenarioIndexes[2]] << endl;
    OutputASM << "004554AF: " << endl;
    OutputASM << "mov [esp+2C]," << Sc_Name_Array[ScenarioIndexes[3]] << endl;
    OutputASM << "004554D4: " << endl;
    OutputASM << "mov [esp+30]," << Sc_Name_Array[ScenarioIndexes[4]] << endl;
    OutputASM << "004554F3: " << endl;
    OutputASM << "mov [esp+30]," << Sc_Name_Array[ScenarioIndexes[5]] << endl;
    OutputASM << "0045550C: " << endl;
    OutputASM << "mov [esp+2c]," << Sc_Name_Array[ScenarioIndexes[6]] << endl;
    OutputASM << "00455531: " << endl;
    OutputASM << "mov [esp+30]," << Sc_Name_Array[ScenarioIndexes[7]] << endl;
    OutputASM << "00455550: " << endl;
    OutputASM << "mov [esp+30]," << Sc_Name_Array[ScenarioIndexes[8]] << endl;
    OutputASM << "00455569: " << endl;
    OutputASM << "mov [esp+2c]," << Sc_Name_Array[ScenarioIndexes[9]] << endl;
    OutputASM << "0045558E: " << endl;
    OutputASM << "mov [esp+30]," << Sc_Name_Array[ScenarioIndexes[10]] << endl;
    OutputASM << "004555AD: " << endl;
    OutputASM << "mov [esp+30]," << Sc_Name_Array[ScenarioIndexes[11]] << endl;
    OutputASM << "004555C6: " << endl;
    OutputASM << "mov [esp+2C]," << Sc_Name_Array[ScenarioIndexes[12]] << endl;
    OutputASM << "004555EB: " << endl;
    OutputASM << "mov [esp+30]," << Sc_Name_Array[ScenarioIndexes[13]] << endl;
    OutputASM << "0045560A: " << endl;
    OutputASM << "mov [esp+30]," << Sc_Name_Array[ScenarioIndexes[14]] << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << endl;
    OutputASM << "00455446: " << endl;
    OutputASM << "cmp [" << Sc_Completed_Array[ScenarioIndexes[0]] << "], ebx" << endl;
    OutputASM << "00455465: " << endl;
    OutputASM << "cmp [" << Sc_Completed_Array[ScenarioIndexes[1]] << "], ebx" << endl;
    OutputASM << "00455484: " << endl;
    OutputASM << "cmp [" << Sc_Completed_Array[ScenarioIndexes[2]] << "], ebx" << endl;
    OutputASM << "004554A3: " << endl;
    OutputASM << "cmp [" << Sc_Completed_Array[ScenarioIndexes[3]] << "], ebx" << endl;
    OutputASM << "004554C2: " << endl;
    OutputASM << "cmp [" << Sc_Completed_Array[ScenarioIndexes[4]] << "], ebx" << endl;
    OutputASM << "004554E1: " << endl;
    OutputASM << "cmp [" << Sc_Completed_Array[ScenarioIndexes[5]] << "], ebx" << endl;
    OutputASM << "00455500: " << endl;
    OutputASM << "cmp [" << Sc_Completed_Array[ScenarioIndexes[6]] << "], ebx" << endl;
    OutputASM << "0045551F: " << endl;
    OutputASM << "cmp [" << Sc_Completed_Array[ScenarioIndexes[7]] << "], ebx" << endl;
    OutputASM << "0045553E: " << endl;
    OutputASM << "cmp [" << Sc_Completed_Array[ScenarioIndexes[8]] << "], ebx" << endl;
    OutputASM << "0045555D: " << endl;
    OutputASM << "cmp [" << Sc_Completed_Array[ScenarioIndexes[9]] << "], ebx" << endl;
    OutputASM << "0045557C: " << endl;
    OutputASM << "cmp [" << Sc_Completed_Array[ScenarioIndexes[10]] << "], ebx" << endl;
    OutputASM << "0045559B: " << endl;
    OutputASM << "cmp [" << Sc_Completed_Array[ScenarioIndexes[11]] << "], ebx" << endl;
    OutputASM << "004555BA: " << endl;
    OutputASM << "cmp [" << Sc_Completed_Array[ScenarioIndexes[12]] << "], ebx" << endl;
    OutputASM << "004555D9: " << endl;
    OutputASM << "cmp [" << Sc_Completed_Array[ScenarioIndexes[13]] << "], ebx" << endl;
    OutputASM << "004555F8: " << endl;
    OutputASM << "cmp [" << Sc_Completed_Array[ScenarioIndexes[14]] << "], ebx" << endl;








    OutputASM << "[DISABLE]" << endl;

    OutputASM.close();

}

void OutputRandomiserInfo(string ModsPath, string app_version, unsigned seed, bool RandHaunters, bool RandScOrd, bool PrevImpSav, bool DialogueFix, bool RandomDialogue)
{
    ofstream RandomiserInfo(ModsPath + "RandomiserInfo.log");
    RandomiserInfo << app_version << endl << endl;


    RandomiserInfo << "Random Haunters: ";
    if (RandHaunters)
        RandomiserInfo << "Enabled" << endl;
    else
        RandomiserInfo << "Disabled" << endl;

    RandomiserInfo << "Haunter speech softlock prevention: ";
    if (DialogueFix)
        RandomiserInfo << "Enabled" << endl;
    else
        RandomiserInfo << "Disabled" << endl;

    RandomiserInfo << "Random Dialogue: ";
    if (RandomDialogue)
        RandomiserInfo << "Enabled" << endl;
    else
        RandomiserInfo << "Disabled" << endl;

    RandomiserInfo << "Random Scenario Order: ";
    if (RandScOrd)
        RandomiserInfo << "Enabled" << endl;
    else
        RandomiserInfo << "Disabled" << endl;

    RandomiserInfo << "Impossible save prevention: ";
        if (PrevImpSav)
            RandomiserInfo << "Enabled" << endl;
        else
            RandomiserInfo << "Disabled" << endl;



    RandomiserInfo << endl;
    RandomiserInfo << endl;
    RandomiserInfo << "Seed: " << seed;

    RandomiserInfo.close();
}


bool DeleteAndRename(string ModsPath, string fileName)
{

    string filePath = ModsPath + fileName;
    string oldName = ModsPath + fileName + ".Randomiser_TEMP";

    if (!remove(filePath.c_str()))
    {
        if (!rename(oldName.c_str(), filePath.c_str()))
        {
            return 1; //ok
        }

        else
        {
            std::cout << "Failed at renaming " << oldName << " to " << fileName << endl;
            return 0; //rename failed
        }

    }

    else
    {
        std::cout << "Failed at removing " << fileName << endl;
        return 0; //remove failed
    }


}
