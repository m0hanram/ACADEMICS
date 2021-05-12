from instabot import Bot
bot = Bot()
bot.login(username="barneystinson101101", password="mohan@10")

######  upload a picture #######
bot.upload_photo("hi.jpg", caption="biscuit eating baby")

######  follow someone #######
bot.follow("elonrmuskk")

######  send a message #######
bot.unfollow_everyone()
