        bool step1 = true;
        int ans = 0;
        while(step1 != false)
        {
            step1 = false;
            for(int i = 0;i < n;i++)
            {
                if(a[i] > b[i])
                {
                    a[i]--;
                    step1 = true;
                }

                if(a[i] < b[i])
                {
                    a[i]++;
                }
            }
            ans++;
        }
        
        cout << ans << endl;
    }
}