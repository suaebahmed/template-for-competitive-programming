### 1 Download latest version(14.2.0) GCC from WinLibs https://winlibs.com/

### 2 Extract the downloaded file to C:\mingw64

### 3 Add the path to the environment variable
```bash
    setx path "%path%; C:\mingw64\bin"
```
### 4 verify the installation
```bash
    g++ --version
```

#### Note: We don't need below code if we are using sublime text editor with these settings
```cpp
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif 
```