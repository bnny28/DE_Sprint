from selene.api import browser
from selenium import webdriver
from selenium.webdriver.chrome.options import Options as ChromeOptions
from webdriver_manager.chrome import ChromeDriverManager

import commands as c


def get_chrome_driver():
    opts = ChromeOptions()
    opts.add_argument("start-maximized")
    return webdriver.Chrome(ChromeDriverManager().install(), options=opts)


if __name__ == '__main__':
    # !!! Долгая операция - 25 мин.!!!
    driver = get_chrome_driver()
    browser.set_driver(driver)

    print("start processing (~25 min) ...")
    c.find_without_experience()
    c.process_current_found("без опыта")
    c.find_more_6_years_experience()
    c.process_current_found("более 6 лет")
    c.find_experience_from_1_to_3_without_title()
    c.process_current_found("1-3 года")
    c.find_experience_from_1_to_3_with_title()
    c.process_current_found("1-3 года")
    c.find_experience_from_3_to_6_with_title()
    c.process_current_found("3-6 лет")
    c.find_experience_from_3_to_6_without_title()
    c.process_current_found("3-6 лет")
    c.save_json()
    print("stop processing...")

    browser.close()
