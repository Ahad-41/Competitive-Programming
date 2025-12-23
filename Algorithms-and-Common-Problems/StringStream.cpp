// s = "{function_id}:{"start" | "end"}:{timestamp}"
// s = "0:start:3", "1:end:2"

stringstream ss(s);
string temp;

getline(ss, temp, ':');
int id = stoi(temp);

getline(ss, temp, ':');
string type = temp;

getline(ss, temp, ':');
int timestamp = stoi(temp);
