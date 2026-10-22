---
title: "hackaclock"
github: "https://github.com/zacianculovici/hackaclock/"
description: "My Stardance BLARE alarm clock!!! Cool 6-button design with bevelled edges."
created_at: "2026-09-09"
---

# hackaclock Retroactive Journal
Total time spent: ~16h 45m (~13h 20m on CAD, ~1h 30m on PCB, ~1h 45m on firmware)
> [!NOTE]
> This journal is retroactive, meaning that I wrote it after my work. Please excuse any inaccuracies. For detailed commit history, see [here](https://github.com/zacianculovici/hackaclock/commits). Also, the time estimates are from hackatime so are quite accurate. 

## Overall challenges
Throughout this project, I have had many challenges, mainly with the CAD side of things, because I learnt that I'm really not very good at 3D modelling. Even when it looked completely fine in blender, I found that it often went bad after I exported it, coming up with thicknesses of 0.1mm and overlapping verticies. Reflecting back, I think I could have done a better case in more like 2h if I used a proper CAD program, but I am proud of my perseverance and the outcome as well. 

## Sep 10 2026 ~2h
Today I did the first actual PCB design, and I got that done in about 1h, because I already had some experience with kicad. After doing the initial schematic and PCB, I created the case design in blender and started with a really simple rectangular prism for me to work on later. 

![10 Sep Screenshot](https://cdn.hackclub.com/01a162e5-8745-7b17-bf2c-ed83150be38d/paste-1792660571164.png)

## Sep 11 2026 ~1h 15m
Today I started locking in on the actual case, making the initial cutout for the angled screen, and impoerted the PCB from kicad. I spent quite a while trying to figure out how to export the board correctly, but I ended up using the `pcb2blender` plugin for kicad, meaning I could do it easily. This was tricky, as I was running kicad 10, and the official `pcb2blender` plugin has not yet been updated to say it works with newer kicad versions. I ended up just importing the plugin manually, because it works just fine with kicad 10. 

![11 Sep Screenshot](https://cdn.hackclub.com/01a162e5-3635-70bc-8274-d16afaa7c520/paste-1792660550752.png)

## Sep 12 2026 ~50m
Today I continued working on the box, adding internal cutout booleans and PCB supports. I imported the display model, and started actually putting everything together into the one model. 

This is the point where I definitely should have swapped to a proper CAD program, but I stupidly (in hindsight) decided to persevere and continue. The boolean cutouts ended up being my biggest problem of all. 

## Sep 19 2026 ~50m
Today I started working on the lid, making a simple extrusion of the box and separating it. This was easy, but then I realised that I hadn't imported the display model correctly! The display was there, but the pins were tiny! I reimported it and fixed it. 

![19 Sep Screenshot](https://cdn.hackclub.com/01a162e3-ff2e-74e6-bb33-21fca18fa8bb/paste-1792660471090.png)

## Sep 20 2026 ~1h 10m
Today I started on the cutout for the display to slot into. I begun with a really simple exact boolean of the display model, but later I realised (tomorrow) that I needed to do it manually for it to work properly. Yet another point of my downfall. 

## Sep 21 2026 ~2h
Today I did the cutout for the display ***manually***, and it took way longer than it orobably should have, as I had lot's of "non-manifold" geometry errors and issues. After I fixed these, I also changed the thickness of the box, as I hadn't really had the right thickness from the start. 

## Sep 22-Sep 27 2026 ~5h 40m
In this time range, it is hard to tell exactly what I did (my bad commit messages fault), but mainly I fixed ***so many*** issues with bad geometry. This is where I really started to regret using blender instead of a proper CAD program, as every time I fixed one issue, another would pop up! I spent ages doing this, and ended up having to redo lots of the boolean cutouts before it would export right. I got the design mostly finished. 

## Sep 28 2026 ~2h 10m
Today, I mainly just made sure everything was done, ensuring the CAD all exported correctly without any non-manifold geometry, which took quite a while. I also deleted the old exports, restructured the folders, and fixed a silly pin connection mistake in the schematic and the PCB. 

## Sep 29 2026 ~1h 10m
Today I did a really simple firmware, where it just connects to local WiFi, and get's the local time and displays it on the screen. I decided to do really barebones firmware to begin with, and then move to a proper RTOS-style more complicated firmware afterwards. 

I also moved all the exports (3D models, gerbers, etc.) into a Production folder for ease of access, and wrote my README. 

![28 Sep Screenshot](https://cdn.hackclub.com/01a162e3-a61f-73f3-a17d-76d6e9c81216/paste-1792660447201.png)

![29 Sep Screenshot](https://cdn.hackclub.com/01a162e3-02dd-74a9-b8da-b45c47c82cc8/paste-1792660404470.png)
