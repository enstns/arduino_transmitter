# flask-file-server

## Getting started

flask-file-server requires **flask** library

```
pip install Flask
```

### Example Request
Need more example? Run code and see [`localhost`](http://127.0.0.1:4000)
*`GET Requests`
    * `to_list_files`:
        * `URL` is  http://127.0.0.1:4000/filelist
        * `PARAMETER` is ;
            * `folder` : to list different folder's files which is in main directory (not necessary if wants to list maindirectory)
        * `TEST URL` server can tested with this message;
            * http://127.0.0.1:4000/filelist
    
    * `to_open_file`:
        * `URL` is  http://127.0.0.1:4000/openfile
        * `PARAMETERS` are ;
            * `file_name` : the selected file name which is wanted to open...,
            * `folder_path` : to define where is selected file is located (not necessary if file in main directory)
        * `TEST URL` server can tested with this message;
            * http://127.0.0.1:4000/openfile?file_name=13.png&folder_path=files\test2

    * `to_update_maindirectory`:
        - `URL` is  http://127.0.0.1:4000/update/maindirectory
        - `BODY` is ;
            ```json
            {
                "password" : "server password to change directory!",
                "new_directory" : "new main directory.."
            }
            ```
