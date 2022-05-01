from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.common.by import By
import time
import urllib.request
import os

def createDirectory(directory):
    try:
        if not os.path.exists(directory):
            os.makedirs(directory)
    except OSError:
        print("Error: Failed to create the directory.")

def crawling_img(name):
    driver = webdriver.Chrome()
    driver.get("https://www.google.co.kr/imghp?hl=ko&tab=wi&authuser=0&ogbl")
    elem = driver.find_element(By.XPATH, '//*[@id="sbtc"]/div/div[2]/input')
    elem.send_keys(name)
    elem.send_keys(Keys.RETURN)

    #
    SCROLL_PAUSE_TIME = 1
    # Get scroll height
    last_height = driver.execute_script("return document.body.scrollHeight")  # 브라우저의 높이를 자바스크립트로 찾음
    while True:
        # Scroll down to bottom
        driver.execute_script("window.scrollTo(0, document.body.scrollHeight);")  # 브라우저 끝까지 스크롤을 내림
        # Wait to load page
        time.sleep(SCROLL_PAUSE_TIME)
        # Calculate new scroll height and compare with last scroll height
        new_height = driver.execute_script("return document.body.scrollHeight")
        if new_height == last_height:
            try:
                driver.find_element(By.CSS_SELECTOR,".mye4qd").click()
            except:
                break
        last_height = new_height

    imgs = driver.find_elements(By.CSS_SELECTOR, ".rg_i.Q4LuWd")
    dir = "./imgs/" + name

    createDirectory(dir) #폴더 생성
    count = 1

    opener = urllib.request.build_opener()
    opener.addheaders = [('User-Agent', 'Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/36.0.1941.0 Safari/537.36')]
    urllib.request.install_opener(opener)
    for img in imgs:
        try:
            img.click()
            time.sleep(2)
            imgUrl = driver.find_element(By.XPATH, '/html/body/div[3]/c-wiz/div[3]/div[2]/div[3]/div/div/div[3]/div[2]/c-wiz/div/div[1]/div[1]/div[3]/div/a/img').get_attribute("src")
            path = dir + "/"
            urllib.request.urlretrieve(imgUrl, path + str(count) + ".png")
            print(str(count) + ".png")
            count = count + 1
            # if count >= 260:
            #     break
        except:
            pass
    driver.close()


searchs = ["사과", "사과과일", "사과나무", "사과재배", "apple fruit", "apple trees", "apple cultivation"]
for search in searchs:
    crawling_img(search)
#
# keyword='사과'
# driver = webdriver.Chrome()
# driver.get("https://www.google.com/imghp?hl=ko__&gws_rd=ssl")
# elem = driver.find_element(By.XPATH, '//*[@id="sbtc"]/div/div[2]/input')
# elem.send_keys(keyword)
# elem.send_keys(Keys.RETURN)
#
#
# print(keyword+' 스크롤 중 .............')
# SCROLL_PAUSE_TIME = 2
#
# last_height = driver.execute_script("return document.body.scrollHeight")
#
# while True:
#     driver.execute_script("window.scrollTo(0, document.body.scrollHeight);")
#     time.sleep(SCROLL_PAUSE_TIME)
#     new_height = driver.execute_script("return document.body.scrollHeight")
#
#     if new_height == last_height:
#         try:
#             driver.find_element(By.CSS_SELECTOR,".mye4qd").click()
#         except:
#             break
#     last_height = new_height
#
#
#
# time.sleep(1)
# imgs = driver.find_elements(By.CSS_SELECTOR,".rg_i.Q4LuWd")
# print(keyword+' 찾은 이미지 개수:', len(imgs))
# # opener=urllib.request.build_opener()
# # opener.addheaders=[('User-Agent','Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/36.0.1941.0 Safari/537.36')]
# # urllib.request.install_opener(opener)
# cnt = 1
# time.sleep(1)
# for img in imgs:
#     try:
#         img.click()
#         time.sleep(2)
#         imgUrl = driver.find_element(By.XPATH, '/html/body/div[3]/c-wiz/div[3]/div[2]/div[3]/div/div/div[3]/div[2]/c-wiz/div/div[1]/div[1]/div[3]/div/a/img').get_attribute("src")
#         opener = urllib.request.build_opener()
#         opener.addheaders = [('User-Agent', 'Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/36.0.1941.0 Safari/537.36')]
#         urllib.request.install_opener(opener)
#         urllib.request.urlretrieve(imgUrl, "./imgs/"+ str(cnt) +".png")
#         print(imgUrl + str(cnt) +".png")
#         cnt = cnt + 1
#     except:
#         pass
#
