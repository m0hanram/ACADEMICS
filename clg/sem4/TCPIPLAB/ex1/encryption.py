from base64 import b64encode
import hashlib
from Cryptodome.Cipher import AES
from Cryptodome.Random import get_random_bytes
import ast
import json


def encrypting(ofile_name, wfile_name, key):
    of = open(ofile_name, "r")
    wf = open(wfile_name, "w")
    for line in of:
        for character in line:
            if (ord(character) >= ord("a")) and (ord(character) <= ord("z")):
                new_character = ord(character) + key
                if new_character > ord("z"):
                    new_character -= 26
                wf.write(chr(new_character))
            elif (ord(character) >= ord("A")) and (ord(character) <= ord("Z")):
                new_character = ord(character) + key
                if new_character > ord("Z"):
                    new_character -= 26
                wf.write(chr(new_character))
            else:
                wf.write(character)


def aes_encryption(ofile_name, wfile_name, password):
    of = open(ofile_name, "r")
    wf = open(wfile_name, "w")
    salt = get_random_bytes(AES.block_size)
    private_key = hashlib.scrypt(
        password.encode(), salt=salt, n=2 ** 14, r=8, p=1, dklen=32)
    cipher_config = AES.new(private_key, AES.MODE_GCM)
    cipher_text, tag = cipher_config.encrypt_and_digest(bytes(of.read(), 'utf-8'))
    inpt = {
        'cipher_text': b64encode(cipher_text).decode('utf-8'),
        'salt': b64encode(salt).decode('utf-8'),
        'nonce': b64encode(cipher_config.nonce).decode('utf-8'),
        'tag': b64encode(tag).decode('utf-8')
    }
    json_data = ast.literal_eval(json.dumps(inpt))
    wf.write(str(json_data))






