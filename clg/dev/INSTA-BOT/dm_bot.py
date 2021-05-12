from instabot import Bot
import time
import numpy as np


def get_new_following(bot, old_following):
    new_following = bot.get_user_following("barneystinson101101")
    id_to_send_hi = list()
    if np.array_equal(np.array(new_following).sort(), np.array(old_following).sort()):
        return []
    else:
        for following in new_following:
            if following not in old_following:
                id_to_send_hi.append(bot, id_to_send_hi)


def send_hi(bot, id_list):
    for id in id_list:
        bot.send_message("Hi", id)


def main():
    bot = Bot()
    bot.login(username="barneystinson101101",
              password="mohan@10")
    print("login successfull")
    try:
        while True:
            old_following = bot.get_user_following("barneystinson101101")
            time.sleep(30)                        # change to 600
            get_new_following(bot, old_following)
    except KeyboardInterrupt:
        pass


if __name__ == "__main__":
    main()
