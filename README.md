#Vehicle Parking management system
>Automated system controlled by an admin and performed by artificial system or sensors.

---

### Table of Contents


- [Description](#description)
- [How To Use](#how-to-use)
- [Author Info](#author-info)

---


## Description
The key processes performed by system are listed below:


#### Entry

- Fetching essential informations like vehicleNumber, size, brandName, and entryTime ,etc
- System is searching for available slots according to the size of vehicle and feasibility of situation

![out7](https://user-images.githubusercontent.com/46133803/85057694-b530d380-b1be-11ea-8c59-b04ac90f5158.png)



#### Exit

- Scan the serial number through sensors
- Searching information of that vehicle and calculating total Bill
- Collect the Bill
- Payment through cash or Online system

![out12](https://user-images.githubusercontent.com/46133803/85057647-acd89880-b1be-11ea-86a1-d6640b32a8a8.png)

#### Database

- A particular day database:- vehicle data, Bill data, net income, Brand data, etc

![out9](https://user-images.githubusercontent.com/46133803/85057698-b6fa9700-b1be-11ea-9e3e-0150acbe83e6.png)


- All time data

![out11](https://user-images.githubusercontent.com/46133803/85057645-ac400200-b1be-11ea-8ef6-b686fb93f1eb.png)

- Brand data to be supplied to brands

![out10](https://user-images.githubusercontent.com/46133803/85057643-ab0ed500-b1be-11ea-800d-1e9c3d703a0e.png)


#### Special features

- Password security through Huffman Coding
![out4](https://user-images.githubusercontent.com/46133803/85057678-b3671000-b1be-11ea-8c45-1f3edc3689f6.png)

- Dealing with brand data
- Consideration of anmolies like wrong vehicle number detection, wrong choice selection by AI drive bot, Less paid or more paid by customer, etc

---

## How To Use

####Compile
```html
    # compile
    $ g++ main.cpp
     
```
####Run
```html
    # run on bash
    $ ./a.out 
    # run on windows cmd
    $ a 
```

---

## Author Info

- Website - [Jay Prakash](home.iitj.ac.in/~prakash.3)

---
