import json
from random import randint
from time import sleep

from selene.api import *
from selene.elements import SeleneCollection

lst = []


def find_without_experience():
    url_search = 'https://hh.ru/search/vacancy?no_magic=true&L_save_area=true&text=python+developer&salary=&' \
                 'currency_code=RUR&experience=noExperience&order_by=relevance&search_period=0&items_on_page=100'
    browser.open_url(url_search)


def find_experience_from_1_to_3_without_title():
    url_search = 'https://kaluga.hh.ru/search/vacancy?no_magic=true&L_save_area=true&text=python+developer+' \
                 'and+name%3A%28not+python+and+not+developer+and+not+' \
                 '%D1%80%D0%B0%D0%B7%D1%80%D0%B0%D0%B1%D0%BE%D1%82%D1%87%D0%B8%D0%BA+and+not+' \
                 '%D0%BF%D1%80%D0%BE%D0%B3%D1%80%D0%B0%D0%BC%D0%BC%D0%B8%D1%81%D1%82%29&salary=&' \
                 'currency_code=RUR&experience=between1And3&order_by=relevance&search_period=0&items_on_page=100'
    browser.open_url(url_search)


def find_experience_from_1_to_3_with_title():
    url_search = 'https://kaluga.hh.ru/search/vacancy?text=python+developer+and+name%3A%28python+or+developer+' \
                 'or+%D1%80%D0%B0%D0%B7%D1%80%D0%B0%D0%B1%D0%BE%D1%82%D1%87%D0%B8%D0%BA+or+' \
                 '%D0%BF%D1%80%D0%BE%D0%B3%D1%80%D0%B0%D0%BC%D0%BC%D0%B8%D1%81%D1%82%29&from=suggest_post&' \
                 'salary=&clusters=true&no_magic=true&ored_clusters=true&items_on_page=100&' \
                 'experience=between1And3&enable_snippets=true'
    browser.open_url(url_search)


def find_experience_from_3_to_6_without_title():
    url_search = 'https://kaluga.hh.ru/search/vacancy?no_magic=true&L_save_area=true&text=python+developer+' \
                 'and+name%3A%28not+python+and+not+developer+and+not+' \
                 '%D1%80%D0%B0%D0%B7%D1%80%D0%B0%D0%B1%D0%BE%D1%82%D1%87%D0%B8%D0%BA+and+not+' \
                 '%D0%BF%D1%80%D0%BE%D0%B3%D1%80%D0%B0%D0%BC%D0%BC%D0%B8%D1%81%D1%82%29&salary=&' \
                 'currency_code=RUR&experience=between3And6&order_by=relevance&search_period=0&items_on_page=100'
    browser.open_url(url_search)


def find_experience_from_3_to_6_with_title():
    url_search = 'https://kaluga.hh.ru/search/vacancy?no_magic=true&L_save_area=true&text=python+developer+' \
                 'and+name%3A%28python+or+developer+or+' \
                 '%D1%80%D0%B0%D0%B7%D1%80%D0%B0%D0%B1%D0%BE%D1%82%D1%87%D0%B8%D0%BA+or+' \
                 '%D0%BF%D1%80%D0%BE%D0%B3%D1%80%D0%B0%D0%BC%D0%BC%D0%B8%D1%81%D1%82%29&salary=&' \
                 'currency_code=RUR&experience=between3And6&order_by=relevance&search_period=0&items_on_page=100'
    browser.open_url(url_search)


def find_more_6_years_experience():
    url_search = 'https://kaluga.hh.ru/search/vacancy?no_magic=true&L_save_area=true&text=python+developer&salary=&' \
                 'currency_code=RUR&experience=moreThan6&order_by=relevance&search_period=0&items_on_page=100'
    browser.open_url(url_search)


def process_current_found(exp: str):
    pages = return_number_found_sheets()
    page = 1
    global lst
    while True:
        vacs = return_all_vacancies_on_sheet()
        lst = lst + process_vacancies(vacs, exp)
        page += 1
        if page > pages:
            break
        open_sheet_by_number(page)
        # Чтобы не ddos-ить HH
        sleep(randint(5, 15))


def return_number_found_sheets() -> int:
    last_page_container_selector = "//div[@class = 'pager']/span[last()]"
    last_page_xpath_selector = ".//a[@class = 'bloko-button']/span"
    res = s(by.xpath(last_page_container_selector)).get_actual_webelement() \
        .find_element_by_xpath(last_page_xpath_selector).text
    print(f'{res} sheets...')
    return int(res)


def return_all_vacancies_on_sheet() -> SeleneCollection:
    all_selector = "//div[@class = 'serp-item']"
    result = ss(by.xpath(all_selector))
    return result


def process_vacancies(all_v: SeleneCollection, exp: str) -> lst:
    title_selector = ".//a[@class = 'serp-item__title']"
    salary_selector = ".//span[@data-qa = 'vacancy-serp__vacancy-compensation']"
    region_selector = ".//div[@data-qa = 'vacancy-serp__vacancy-address']"
    inner_lst = []
    for item in all_v.get_actual_webelements():
        iter_dict = {"title": item.find_element_by_xpath(title_selector).text.strip(), "work experience": exp}
        if i := item.find_elements_by_xpath(salary_selector):
            iter_dict["salary"] = i[0].text.replace('\u202f', '').strip()
        else:
            iter_dict["salary"] = "не указано"
        if i := item.find_elements_by_xpath(region_selector):
            iter_dict["region"] = i[0].text.replace('\u202f', '').strip()
        else:
            iter_dict["region"] = "не указано"
        inner_lst.append(iter_dict)
    return inner_lst


def open_sheet_by_number(i: int):
    page_selector = "//a[@data-qa = 'pager-page']/span[text()='" + str(i) + "']"
    s(by.xpath(page_selector)).click()


def save_json():
    with open('parse_data.json', 'w', encoding='utf-8') as f:
        json.dump({'data': lst}, f, ensure_ascii=False, indent=4)
