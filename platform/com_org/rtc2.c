//sample code for creating a region
#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/ioport.h>
#include<linux/delay.h>
#include<asm/io.h>

#define RTC_ADDRESS 0X70
#define RTC_DATA 0X71

#define SECONDS 	0X00
#define MINUTES 	0X02
#define HOURS 		0X04
#define DAY_WEEK 	0X06
#define DAY_MONTH 	0X07
#define MONTH 		0X08
#define YEAR 		0X09

#define REGA		0X0A
#define REGB		0X0B
#define REGC		0X0C
#define REGD		0X0D

MODULE_LICENSE("GPL");

unsigned char rtc_read(int address)
{
	outb_p(address, RTC_ADDRESS);
	return inb_p(RTC_DATA);
}

static int mod_init(void)
{
	unsigned char regb = rtc_read(REGB);
	
	pr_info("Register B:%02x\n",regb);

	if(regb & 0x01) {
		pr_info("Daylight saving enabled\n");
	} else {
		pr_info("Daylight saving disabled\n");
	}
	
	if(regb & 0x02) {
                pr_info("24 Hour Mode\n");
        } else {
                pr_info("12 Hour Mode\n");
        }

	if(regb & 0x04) {
                pr_info("Data in binary format\n");
        } else {
                pr_info("Data in BCD Format\n");
        }

	pr_info("Hours:%02x\t Minutes:%02x\t Seconds:%02x\n",rtc_read(HOURS),rtc_read(MINUTES),rtc_read(SECONDS));
	ssleep(5);
	pr_info("Hours:%02x\t Minutes:%02x\t Seconds:%02x\n",rtc_read(HOURS),rtc_read(MINUTES),rtc_read(SECONDS));
	return 0;
}

static void mod_exit(void)
{

}

module_init(mod_init);
module_exit(mod_exit);
