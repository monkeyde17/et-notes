class Solution {
    public:
        void reverseWords(string &s) {
            stack<string> st;
            stringstream sio;

            sio << s;

            while (!sio.eof()) {
                string str;
                sio >> str;
                if (str.length() > 0) st.push(str);
            }

            s = "";
            if (st.empty()) return ;

            s = st.top();
            st.pop();
            while (!st.empty())
            {
                s += " ";
                s += st.top();
                st.pop();
            }
        }
};
