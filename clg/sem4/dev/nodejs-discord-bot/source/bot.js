require('dotenv').config();

const {Client, WebhookClient} = require('discord.js');
const PREFIX='$';

const webhookClient = new WebhookClient(
    process.env.WEBHOOK_ID,
    process.env.WEBHOOK_TOKEN
);

const client = new Client({
    partials:['MESSAGE','REACTION']
});
client.login(process.env.DISCORDJS_BOT_TOKEN);

client.on('ready', () => {
    console.log(`${client.user.tag} has logged into the server...`);
});

client.on('message', (message)=>{
    console.log(`[${message.author.tag}]: ${message.content}`);
});

client.on('message', (message)=>{
    if(message.author.bot)
    {
        return;
    }
    if(message.content === 'hello')
    {
        message.channel.send('hello');
    }
});

client.on('message', (message)=>{
    if(message.author.bot) {
        return;
    }
    if(message.content.startsWith(PREFIX)) {
        const [CMD_NAME,...args] = message.content
        .trim()
        .substring(PREFIX.length)
        .split(/\s+/);
        if(CMD_NAME === 'kick') {
            if(!message.member.hasPermission('KICK_MEMBERS'))
                return message.reply('Yoiu do not have the permission to kick members');
            if(args.length === 0) 
                return message.reply('Please provide an ID');
            const member = message.guild.members.cache.get(args[0]);
            if(member){
                member
                .kick('sorry your not needed anymore')
                .then((member) => message.channel.send(`${member} was kicked`))
                .catch((err) => message.channel.send('cannot kick the user'));
            }
            else{
                message.channel.send('The user was not found');
            }
        }
        else if(CMD_NAME === 'ban')
        {
            if(!message.member.hasPermission('BAN_MEMBERS')) 
                return message.reply('You dont have the permission to do so');
                if(args.length === 0) 
                return message.reply('Please provide an ID');
        
            try{
                const user =(async()=> await message.guild.members.ban(args[0]));
                message.channel.send('User banned successfully...');
            }
            catch(err){
                console.log(err);
                message.channel.send('An error occured...');
            }

        }
        else if(CMD_NAME === 'announce')
        {
            const msg = args.join(' ');
            webhookClient.send(msg);
        }
    }
});

client.on('messageReactionAdd',(reaction,user) => {
    const { name } = reaction.emoji;
    const member = reaction.message.guild.members.cache.get(user.id);
    if(reaction.message.id === '791307649932853248'){
        switch(name){
            case '🎆':
                member.roles.add('791290751266586646');
                break;
            case '🦾':
                member.roles.add('791290814537531433');
                break;
            case '⏩':
                member.roles.add('791290850642493441');
                break; 
            case '❄️':
                member.roles.add('791290885044174869');
                break;        
        }
    }
});

client.on('messageReactionRemove',(reaction,user) => {
    const { name } = reaction.emoji;
    const member = reaction.message.guild.members.cache.get(user.id);
    if(reaction.message.id === '791307649932853248'){
        switch(name){
            case '🎆':
                member.roles.remove('791290751266586646');
                break;
            case '🦾':
                member.roles.remove('791290814537531433');
                break;
            case '⏩':
                member.roles.remove('791290850642493441');
                break; 
            case '❄️':
                member.roles.remove('791290885044174869');
                break;        
        }
    }
});
