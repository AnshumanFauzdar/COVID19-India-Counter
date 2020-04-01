# COVID19 India Counter Display
![pic1](https://github.com/AnshumanFauzdar/COVID19-India-Counter/blob/master/img001.JPG)

## Parsing Information
  - Website used for parsing information : https://www.worldometers.info/coronavirus/country/india/
  - API used for parsing information : https://thingspeak.com/apps/thinghttp 
  ![pic2](https://github.com/AnshumanFauzdar/COVID19-India-Counter/blob/master/img003.jpg)
  - use Xpath for PaseString:
    ```
    URL:
    https://www.worldometers.info/coronavirus/country/india/
    ParseString: 
    //*[@id="maincounter-wrap"]/div/span 

    URL:
    https://www.mohfw.gov.in
    ParseString: 
    //*[@id="site-dashboard"]/div/div/div/div/ul/li[1]/strong
  - Used HTTP request in arduino 
  
## Materials used:

1. Wemos D1 R2
2. OLED Display
3. Jumper Wires
4. Power supply 
5. Working Internet XD

## Code:

Code is simplified to use on the go, just change your SSID, Password and API and get a COVID-19 counter

# COVID-19 Health Advisory : PLEASE STAY AT HOME!!
