import requests
import bs4
import re
import os
import zipfile

url = 'https://www.gradescope.com/courses/604089'
res = requests.get(url)

cookies = {
    "_ga": "GA1.2.2028189747.1705911701",
    "_gid": "GA1.2.478437629.1705911701",
    "signed_token": "UUhCQVoxRjl6YzRUODhPSW9nK3ovVktXSEdIZjdMdEZPRnlESHB4cHBWND0tLVRMcGZkd3kzVTkwVDlNbnMrS0FVOGc9PQ%3D%3D--9a08012bbc5f2412c88be3ccda0d2d16005b4c2c",
    "remember_me": "bXJsMk1UcXZ6bjgwTVlKOCtxaHhUQT09LS1DZTFEa3hkQi9ZUHhoSk9NV05uTXRnPT0%3D--b78f337a5cbf4422863efd52f8c0f996be9b0bce",
    "apt.uid": "AP-1BQVLBSZC216-2-1705911813208-17372756.0.2.9946b94a-0f5c-41d4-bc77-ae627cad696c",
    "apt.sid": "AP-1BQVLBSZC216-2-1705915087352-19455373",
    "_gradescope_session": "Y2VCaFdWamxDRU5STGkzMDBKTVU0WExHa0VwcVRxdG9aWm5nSSs0L2c5S1ZPKzZQZno3alpsd0VPT3JRSGxoTVJRU0JWemJTakwxeHVycSt1akMrQklCeVI5ODBsTWRCUFYrNE1kU3huQjRxVWN5WlE1SUw2ZWdMZEtFdE80SnI0Yi83aTdlSnU1SS9OMTVDNUZXMGV5G2ZEZW5UbEo3RVZUNmpLVHltcWlPSkJWV2JDRjZzOFhDTjhaUjhmQU83UzZub0g3K1phT2QrNzlNMW10S1J0aEpRT2J1bDUvLzN5Ty9zNTJ2OHR1TTJqbDYzR0xCUUs5R2JDRVdHdm1wcHBGVW0vektmREY2aWtuTzNxbDBMUTZGaU1CajVJeTdWZkJNcDBac2JQckdMRkFsdFBlNmJrSmp3dkD6cDhXZklkRzFyeWtvNHlEYnpxVEZ4enUrU05hUWI5SC9WWDRvMEsyODNGMklGZjlsaFE3aktlMmlUZ2g4cWM0dDZPUmZSVGNucExZYldMYnJiUkpPRWN0azhPdz09LS1RTjNYa1RDRCtwZVJONlVWS0hzbkdRPT0%3D--0fa1993035f6b5ee4d684c6b829424400ad18b1d"
}

response = requests.get(url, cookies=cookies)
soup = bs4.BeautifulSoup(response.text, 'html.parser')
# print(soup.prettify())
a_tags = soup.find_all('a')

#download all files
for tag in a_tags:
    try : 
        if tag != None and re.search(r'submissions', tag.get('href')) != None:
            file_name = tag.get('aria-label')[9:] + '.zip'
            response = requests.get( 'https://www.gradescope.com' + tag.get('href') + '.zip', cookies=cookies)
            if response.status_code == 200:
                with open(file_name, 'wb') as file:
                    file.write(response.content)
    except:
        pass


# unzip all files
folder_path = os.getcwd()

for filename in os.listdir(folder_path):
    if filename.endswith('.zip'):
        file_path = os.path.join(folder_path, filename)

        with zipfile.ZipFile(file_path, 'r') as zip_ref:
            extract_folder = os.path.join(folder_path, filename[:-4])
            os.makedirs(extract_folder, exist_ok=True)
            zip_ref.extractall(extract_folder)
            print(f"Extracted {filename} into {extract_folder}")

        # Remove the zip file after extraction
        os.remove(file_path)
        print(f"Removed {filename}")