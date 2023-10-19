def rsa_generate_keys(p, q):
    n = p * q
    phi_n = (p - 1) * (q - 1)

    # Common choice for e
    e = 17
    d = mod_inverse(e, phi_n)
    return (e, n), (d, n)

def rsa_encrypt(message, public_key):
    e, n = public_key
    return [pow(ord(char), e, n) for char in message]

def rsa_decrypt(encrypted_message, private_key):
    d, n = private_key
    return ''.join(chr(pow(char, d, n)) for char in encrypted_message)

def mod_inverse(e, phi_n):
    # Extended Euclidean Algorithm for finding modular inverse
    a, b, u = 0, phi_n, 1
    while e > 0:
        q = b // e
        e, a, b, u = b % e, u, e, a - q * u
    if b == 1:
        return a % phi_n
    raise ValueError("Modular inverse does not exist")

# Example usage
p = 61
q = 53
public_key, private_key = rsa_generate_keys(p, q)

message = "Merry Christmas Man! Starting when you crack this, we are starting a book club. First book: The Pig That Wants to Be Eaten by Julian Baggini."
encrypted = rsa_encrypt(message, public_key)
decrypted = rsa_decrypt(encrypted, private_key)

print("Original message:", message)
print("Encrypted message:", encrypted)
print(len(encrypted))
print("Decrypted message:", decrypted)
