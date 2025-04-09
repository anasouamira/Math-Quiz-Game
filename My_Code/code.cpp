#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
using namespace std;

enum enLevels
{
    Easy = 1,
    Med = 2,
    Hard = 3,
    MixLevel = 4
};
enum enOpType
{
    Add = 1,
    Sub = 2,
    Mul = 3,
    Div = 4,
    MixOp = 5
};

struct stResultInfo
{
    short NumOfQuestions = 0,
        RightAnswers = 0,
        WrongAnswers = 0;
    enLevels QuestionLevel;
    enOpType OpType;
};

short RandomNumber(short From, short To)
{
    return rand() % (To - From + 1) + From;
}

short AddOp(short Nub1, short Nub2)
{

    return Nub1 + Nub2;
}
short SubOp(short Nub1, short Nub2)
{

    return Nub1 - Nub2;
}
short MulOp(short Nub1, short Nub2)
{

    return Nub1 * Nub2;
}
short DivOp(short Nub1, short Nub2)
{

    return Nub1 / Nub2;
}

string strOperatorType(enOpType OpType)
{

    switch (OpType)
    {
    case enOpType::Add:
        return "+";

    case enOpType::Sub:
        return "-";

    case enOpType::Div:
        return "/";

    case enOpType::Mul:
        return "*";
    }
}
short GetSolutionOf(short Nub1, short Nub2, enOpType OpType)
{

    switch (OpType)
    {
    case enOpType::Add:
        return AddOp(Nub1, Nub2);

    case enOpType::Div:
        return DivOp(Nub1, Nub2);

    case enOpType::Mul:
        return MulOp(Nub1, Nub2);

    case enOpType::Sub:
        return SubOp(Nub1, Nub2);
    }
}

void GetResultOfOperation(short Answer, short Solution)
{

    if (Answer == Solution)
    {
        cout << "Right Answer :-)" << endl;
        system("color 2f");
    }
    else
    {
        cout << "Wrong Answer :-(" << endl;
        cout << "the Right Answer is : " << Solution << endl;
        system("color 4f");
    }
}
enOpType RandomOpType()
{
    short RandomOpType = RandomNumber(1, 4);
    return (enOpType)RandomOpType;
}
enLevels RandomLevel()
{
    short RandomLevel = RandomNumber(1, 3);
    return (enLevels)RandomLevel;
}
void FillArrayWithRandomNumbers(short Array[10])
{
    for (short i = 0; i <= 5; i++)
    {
        Array[i] = RandomNumber(0, 5);
    }
}

short GetNumberOperationLevel(enLevels Levels)
{
    short RandomKey[6];
    short Number;
    FillArrayWithRandomNumbers(RandomKey);
    switch (Levels)
    {
    case enLevels::Easy:
        do
        {
            Number = RandomNumber(1, 10) + RandomKey[RandomNumber(0, 5)];
        } while (Number > 10);
        return Number;

    case enLevels::Med:
        do
        {
            Number = RandomNumber(10, 50) + RandomKey[RandomNumber(0, 5)];
        } while (Number < 10 || Number > 50);
        return Number;

    case enLevels::Hard:
        do
        {
            Number = RandomNumber(50, 100) + RandomKey[RandomNumber(0, 5)];
        } while (Number < 50 || Number > 100);
        return Number;
    }
}
short RedQuestionLevel(string message)
{
    short Number;
    do
    {
        cout << message;
        cin >> Number;

    } while (Number < 1 || Number > 4);
    return Number;
}
short RedQuestionType(string message)
{
    short Number;
    do
    {
        cout << message;
        cin >> Number;

    } while (Number < 1 || Number > 5);
    return Number;
}
short RedNumberOfQuestions(string message)
{
    short Number;
    do
    {
        cout << message;
        cin >> Number;

    } while (Number < 1);
    return Number;
}

void QuizGame(enLevels Level, enOpType OpType, stResultInfo &ResultInfo)
{

    short Nub1, Nub2, Answer;

    if (Level == enLevels::MixLevel)
        Level = RandomLevel();

    if (OpType == enOpType::MixOp)
        OpType = RandomOpType();

    Nub1 = GetNumberOperationLevel(Level);
    Nub2 = GetNumberOperationLevel(Level);

    cout << Nub1 << "  " << strOperatorType(OpType) << "  " << Nub2 << " : ";
    cout << "\n";
    cout << "__________________" << endl;
    cout << "Answer : ";
    cin >> Answer;
    cout << "__________________" << endl;

    short Solution = GetSolutionOf(Nub1, Nub2, OpType);
    GetResultOfOperation(Answer, Solution);

    if (Answer == Solution)
        ResultInfo.RightAnswers++;
    else
        ResultInfo.WrongAnswers++;
}

stResultInfo ReadResult(short NumOfQuestions, short RightAnswers, short WrongAnswers, enLevels QuestionLevel, enOpType OpType)
{

    stResultInfo ResultInfo;

    ResultInfo.NumOfQuestions = NumOfQuestions;
    ResultInfo.RightAnswers = RightAnswers;
    ResultInfo.WrongAnswers = WrongAnswers;
    ResultInfo.QuestionLevel = QuestionLevel;
    ResultInfo.OpType = OpType;

    return ResultInfo;
}

string GetNameLevels(enLevels Level)
{
    string Names[4] = {"Easy", "Med", "Hard", "Mix"};
    short level = (short)Level;
    return Names[level - 1];
}
string GetNameOptype(enOpType Optype)
{

    string Names[5] = {"Add", "Sub", "Mul", "Div", "Mix"};
    short type = (short)Optype;
    return Names[type - 1];
}

void PrintResultGame(stResultInfo GameResult)
{

    cout << endl;
    cout << "=============[End Game]============" << endl;
    cout << "Number Of Questions     : " << GameResult.NumOfQuestions << endl;
    cout << "Question Level          : " << GetNameLevels(GameResult.QuestionLevel) << endl;
    cout << "OpType                  : " << GetNameOptype(GameResult.OpType) << endl;
    cout << "Number of Right Answers : " << GameResult.RightAnswers << endl;
    cout << "Number of Wrong Answers : " << GameResult.WrongAnswers << endl;
    cout << "=============[End Game]============" << endl;
}

stResultInfo PlayMathGame()
{

    stResultInfo ResultInfo;
    short NumOfQuestions = RedNumberOfQuestions("How many Questions do you want answer : ");
    enLevels QuestionLevel = (enLevels)RedQuestionLevel("Enter Question Level [1] Easy, [2] Med, [3] Hard, [4] Mix : ");
    enOpType OpType = (enOpType)RedQuestionType("Enter Question Level [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix  : ");

    short RightAnswers, WrongAnswers;

    for (short Counter = 1; Counter <= NumOfQuestions; Counter++)
    {
        cout << "_________________________________________" << endl;
        cout << "Question [" << Counter << "] : \n"
            << endl;
        QuizGame(QuestionLevel, OpType, ResultInfo);
        cout << endl;
    }

    RightAnswers = ResultInfo.RightAnswers;
    WrongAnswers = ResultInfo.WrongAnswers;

    return ReadResult(NumOfQuestions, RightAnswers, WrongAnswers, QuestionLevel, OpType);
}
void ResetScreen()
{
    system("cls");
    system("color 0f");
}

void StartGame()
{

    char PlayAgain = 'Y';
    do
    {
        ResetScreen();
        stResultInfo GameResult = PlayMathGame();
        PrintResultGame(GameResult);
        cout << endl
            << "Do you want to play again (Y/N)? ";
        cin >> PlayAgain;
    } while (PlayAgain == 'Y');
}

short main()
{
    srand((unsigned)time(NULL));
    StartGame();

    return 0;
}