class Solution {
public:
  bool isValid(string s) {
    stack<char> opening_brackets;

    for (const char c : s) {
      if (c == '(' || c == '[' || c == '{') {
        opening_brackets.push(c);
      }

      else {
        if (opening_brackets.empty())
          return false;

        const char opening_bracket = opening_brackets.top();
        opening_brackets.pop();

        switch (c) {
        case ')':
          if (opening_bracket != '(')
            return false;
          break;
        case ']':
          if (opening_bracket != '[')
            return false;
          break;
        case '}':
          if (opening_bracket != '{')
            return false;
          break;
        }
      }
    }

    return opening_brackets.size() == 0;
  }
};
