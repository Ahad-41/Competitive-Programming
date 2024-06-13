void answer(){
    int length[3]; cin >> length[0] >> length[1] >> length[2];
    sort(length, length+3);
    
    if(length[2] * length[2] == (length[0]*length[0]) + (length[1]*length[1])){
        cout << "yes" << endl;
    }
    else cout << "no" << endl;
}
