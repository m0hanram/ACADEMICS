import json
from base64 import b64decode
import hashlib
from Cryptodome.Cipher import AES


def decrypting(ofile_name, wfile_name, key):
    of = open(ofile_name, "r")
    wf = open(wfile_name, "w")
    for line in of:
        for character in line:
            if (ord(character) >= ord("a")) and (ord(character) <= ord("z")):
                new_character = ord(character) - key
                if new_character < ord("a"):
                    new_character += 26
                wf.write(chr(new_character))
            elif (ord(character) >= ord("A")) and (ord(character) <= ord("Z")):
                new_character = ord(character) - key
                if new_character < ord("A"):
                    new_character += 26
                wf.write(chr(new_character))
            else:
                wf.write(character)
    of.close()
    wf.close()


def aes_decryption(ofile_name, wfile_name, password):
    with open(ofile_name) as f:
        d = f.read()
    wf = open(wfile_name, "w")
    data = singleQuoteToDoubleQuote(d)
    js = json.loads(data)
    salt = b64decode(js["salt"])
    cipher_text = b64decode(js["cipher_text"])
    nonce = b64decode(js["nonce"])
    tag = b64decode(js["tag"])
    private_key = hashlib.scrypt(
        password.encode(), salt=salt, n=2 ** 14, r=8, p=1, dklen=32)
    cipher = AES.new(private_key, AES.MODE_GCM, nonce=nonce)
    decrypted = cipher.decrypt_and_verify(cipher_text, tag)
    wf.write(bytes.decode(decrypted))


def singleQuoteToDoubleQuote(singleQuoted):
    cList = list(singleQuoted)
    inDouble = False;
    inSingle = False;
    for i, c in enumerate(cList):
        if c == "'":
            if not inDouble:
                inSingle = not inSingle
                cList[i] = '"'
        elif c == '"':
            inDouble = not inDouble
    doubleQuoted = "".join(cList)
    return doubleQuoted