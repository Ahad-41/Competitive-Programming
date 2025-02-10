vector<ll> indx(n, -1);
  stack<ll> st;
  for (ll i = n-1; i >= 0; i--) {
      while (!st.empty() and arr[st.top()] <= arr[i]) st.pop();
      if (!st.empty()) indx[i] = st.top();
      st.push(i);
  }
