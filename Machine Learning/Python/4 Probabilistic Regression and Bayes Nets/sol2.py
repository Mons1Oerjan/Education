from lea import *

alternator_broken = Lea.boolProb(1, 1000)
fan_belt_broken = Lea.boolProb(2, 100)

battery_charging = Lea.buildCPT(
    (alternator_broken & fan_belt_broken, Lea.boolProb(0, 1000)),
    (alternator_broken & ~fan_belt_broken, Lea.boolProb(0, 1000)),
    (~alternator_broken & fan_belt_broken, Lea.boolProb(0, 1000)),
    (~alternator_broken & ~fan_belt_broken, Lea.boolProb(995, 1000))
)

battery_flat = Lea.buildCPT(
    (~battery_charging, Lea.boolProb(90, 100)),
    (battery_charging, Lea.boolProb(10, 100))
)

car_does_not_start = Lea.buildCPT(
    (battery_flat, Lea.boolProb(100,100)),
    (~battery_flat, Lea.boolProb(5, 100))
)

print('2.1) Draw a causal model of this system.')
print('See pdf file.')

print('2.2) What is the probability that the alternator is broken given that the car won\'t start?')
print(Pf(alternator_broken.given(car_does_not_start)))

print('2.3) What is the probability that the fan belt is broken given that the car won\'t start?')
print(Pf(fan_belt_broken.given(car_does_not_start)))

print('2.4) What is the probability that the fan belt is broken given that the car won\'t start'
      ' and the alternator is broken?')
print(Pf(fan_belt_broken.given(car_does_not_start & alternator_broken)))

print('2.5) What is the probability that the alternator and the fan belt is broken given that the car won\'t start?')
print(Pf((alternator_broken & fan_belt_broken).given(car_does_not_start)))
