import requests
from hashlib import blake2b


class casher():
    def casher_simulation():
        print("Welcome to Carpool")
        userId = input("Please type your id: ")
        if len(userId) == 10:
            
            money = input("Introduce the money you want to add to your account ")
            if money:
                money_int= int(money)
                if money_int > 0:
                    token = f"Hi9@yBl4$j8WM91*4Wf8{userId}{money}"
                    hash = hashlib.blake2b(token.encode())
                    key = hash.hexdigest()
                    
                    REQUEST_URL = f"https://carpool-arduino-backend.herokuapp.com/login/?user_id={userId}&money={money}&abc={key}"
                    _request = requests.get(REQUEST_URL)
                    if _request:
                        print("Your transaction was successful, see you soon!")
                else:
                    print("Something went wrong, try again. ")
                    casher.casher_simulation()
            else:
                print("Something went wrong, try again.")
                casher.casher_simulation()
                
        else:
            print("Something went wrong, try again. ")
            casher.casher_simulation()


if __name__ == '__main__':
    casher.casher_simulation()
