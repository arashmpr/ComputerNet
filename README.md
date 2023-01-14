## Usage
### How To Compile
For compilation use the following command in __ftpclient/__ and __ftpserver/__ directories
```bash
make
```
* Note: Ensure you have __g++__ on your computer
### How To Run
#### Server
```bash
./ftpserver.out config.json
```
#### Client
```bash
./ftpclient.out
```
## Supported Commands
| Template            | Example          | Description                             |
| ------------------- | ---------------- | --------------------------------------- |
| user "username"     | user Ali         | enter username for authentication       |
| pass "password"     | pass 1234        | enter password for authentication       |
| upload "filename"   | upload co.json   | admin uploads file to FILE  |
| retr "filename"     | retr config.json | download file                           |
| help                | help             | get help message for commands           |
| quit                | quit             | logout from account                     |
