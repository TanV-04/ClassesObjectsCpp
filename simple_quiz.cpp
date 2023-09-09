// #include <iostream>
// #include<string>
// #include<vector>
// #include<algorithm>

// this library includes everything
#include <bits/stdc++.h>
using namespace std;

class Quiz
{

public:
  int score = 0;

  // create two vectors (dynamic sized arrays)
  vector<string> Questions;
  vector<string> Answers;

public:
  // add questions
  void addQues()
  {
    Questions.push_back("Capital of India?");
    Questions.push_back("Capital of France?");
    Questions.push_back("Capital of Germany?");
  }

  int checkAnswer(string ans, int index)
  {

    // converting the standard and user answers to lowercase for easy comparison
    transform(ans.begin(), ans.end(), ans.begin(), ::tolower);
    transform(Answers[index].begin(), Answers[index].end(), Answers[index].begin(), ::tolower);
    
    return ans == Answers[index];
  }

  void takeQuiz()
  {

    // loops through the Questions vector
    for (int i = 0; i < Questions.size(); i++)
    {
      cout << "Q. " << i + 1 << " " << Questions[i] << endl;
      cout << endl;
      cout << "Your answer: " << endl;
      string Answer;
      getline(cin, Answer);

      // i here is the index value for the vector array Answers
      if (checkAnswer(Answer, i) == 1)
      {
        cout << "correct!" << endl;
        score = score + 1;
      }
      else
      {
        cout << "incorrect! correct answer: " << Answers[i] << endl;
      }
    }
  }

  int getScore()
  {
    return score;
  }
};

int main()
{
  Quiz Q1;

  // add answers to the vector Answers
  Q1.Answers.push_back("New Delhi");
  Q1.Answers.push_back("Paris");
  Q1.Answers.push_back("Berlin");

  cout << "Welcome User!" << endl;
  cout << endl;

  Q1.addQues();
  cout << endl;
  Q1.takeQuiz();
  cout << endl;
  cout << "your score is " << Q1.getScore() << " out of three";
}
