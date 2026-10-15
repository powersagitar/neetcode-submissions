class MinStack {
public:
  MinStack() {}

  void push(int val) {
    stack.push_back(val);

    if (minElement.empty()) {
      minElement.push_back(val);
    } else if (val < minElement.back()) {
      minElement.push_back(val);
    } else {
      minElement.push_back(minElement.back());
    }
  }

  void pop() {
    stack.pop_back();
    minElement.pop_back();
  }

  int top() {
    return stack.back();
  }

  int getMin() {
    return minElement.back();
  }

private:
  vector<int> stack;
  vector<int> minElement;
};
