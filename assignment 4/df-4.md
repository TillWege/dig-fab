---
number: 4
title: 'Assignment 4 - Laser Cutting'
course: 'df'
pubDate: 'Nov 6 2023'
---

## Assigment
This weeks assignemnt was to design and fabricate a Design that could be assembled via press-fitting using a laser cutter. This would involve considering the material properties, such as material thickness and stiffness while designing the parts. Due to the way that lasercutting works, the parts would also have to be designed in such a way that they could be assembled from multiple two dimensional parts.

## Designing
For my project i chose to design a small airplane. The main plane body and the wings were to be produced as different pieces that could then be assebled by pressfitting the wings into the main body. As Material I would use cardboard with a thickness of 3.5mm. The design was done in Fusion 360. The design files can be found [here](). The main design of the plane was based off of the [MQ-9 Reaper Drone](https://de.wikipedia.org/wiki/General_Atomics_MQ-9). As such the first step was importing a refernce image into fusion. I traced the main outline using Curves to create a sketch of the main body.

![Sketch](/df/df-4a.png)

While doing this I used fusion's parametric modeling capabilities to make sure that the main body would be able to fit the wings. To do this I created a variable that would hold the material thickness of 3.5mm. This would come in handy later in case that the material would behave slightly different then expected. While designing the plane body I also made multitple small cutouts into which the wings could later be pressed. 

After creating the main body I ten designed one of the wings. 

![Wing](/df/df-4b.png)

While designing the wing I was carefull to only use every alternating slot in the main body. Besides that the wings would completely symmetrical along the centerline. This would allow me to only design one wing and then just flip it after laser cutting.

One of the main design considerations during this project was the material thickness. With just 3.5mm of cardboard the weight of the wings could have proven a problem for the main part. To counteract this I decided that I would use two equal parts of the main body together. These two parts would then be held together by the wings. This would allow me to effectively double the thickness of the main body. To do this I lenghtend the tabs that the wings would use to connect to the main body to double the material width. I also added to more cutouts to the main body at the ends of it. I then created a small connector piece that could be used to connect the two main body parts together. 

![Connector](/df/df-4c.png)

## Laser Cutting

Laser cutting of the designed pieces was very easy. Using the laser cutting extension for fusion I was able to easily convert the created sketches into dxf files. These files could then be send to the laser Cutter. For settings I used 100% of the power with 70% speed. This resulted in a clean cut with no burn marks on the material.

## Result

After pressing the pieces together this is the resulting plane. The structure is more stable then expected due to both, the wings holding the two main body parts together and the material thickness of the cardboard.

![Result](/df/df-4d.jpg)