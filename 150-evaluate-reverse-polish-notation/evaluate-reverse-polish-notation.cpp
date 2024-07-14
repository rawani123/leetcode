class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stack;
    
        for (const string& token : tokens) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            int b = stack.top(); stack.pop();
            int a = stack.top(); stack.pop();
            int result;
            if (token == "+") {
                result = a + b;
            } else if (token == "-") {
                result = a - b;
            } else if (token == "*") {
                result = a * b;
            } else if (token == "/") {
                result = a / b;
            }
            stack.push(result);
        } else {
            stack.push(stoi(token));
        }
    }
    
    return stack.top();
}
};