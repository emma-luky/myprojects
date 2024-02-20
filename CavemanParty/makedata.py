import datetime

import os, django
os.environ.setdefault("DJANGO_SETTINGS_MODULE", "cavemanParty.settings")
django.setup()

from django.core.files.base import ContentFile
from party.models import User, Caveman, Type

def midnight(month, day):
    if month < 11 or month == 11 and day < 5:
        tz = datetime.timezone(datetime.timedelta(hours=-6), "MDT")
    else:
        tz = datetime.timezone(datetime.timedelta(hours=-7), "MST")
    return datetime.datetime(2023, month, day, 11, 59, 59, 999999, tz)

def initial_data():

    emma = User.objects.create_superuser("emma", "emma07315@gmail.com", "emma")

    #dummy caveman
    Type.objects.create(
        name="Oompa Loompa",
        used=True
    )
    # caveman1 = Caveman.objects.create(
    #     name="emma",
    #     type=OompaLoompa,
    # )
    Type.objects.create(
        name="Country",
        used=True
    )
    # caveman2 = Caveman.objects.create(
    #     name="isabel",
    #     type=Country,
    # )

    Type.objects.create(
        name="Baby"
    )
    Type.objects.create(
        name="Disco"
    )
    Type.objects.create(
        name="Feral"
    )
    Type.objects.create(
        name="Alien"
    )
    Type.objects.create(
        name="Corporate"
    )
    Type.objects.create(
        name="Sexy"
    )
    Type.objects.create(
        name="Diseased"
    )
    Type.objects.create(
        name="Emo"
    )
    Type.objects.create(
        name="Party"
    )
    Type.objects.create(
        name="Preppy"
    )
    Type.objects.create(
        name="Painter"
    )
    Type.objects.create(
        name="Hairy"
    )
    Type.objects.create(
        name="Pregnant"
    )
    Type.objects.create(
        name="Redneck"
    )
    Type.objects.create(
        name="Rainbow"
    )
    Type.objects.create(
        name="Vegan"
    )
    Type.objects.create(
        name="Fairy"
    )
    Type.objects.create(
        name="Zombie"
    )
    Type.objects.create(
        name="Ice Spice"
    )
    Type.objects.create(
        name="Santa"
    )
    Type.objects.create(
        name="Gangster"
    )
    Type.objects.create(
        name="Puberty"
    )
    Type.objects.create(
        name="Detective"
    )
    Type.objects.create(
        name="White Girl"
    )
    Type.objects.create(
        name="Skater"
    )
    Type.objects.create(
        name="Ski Bum"
    )
    Type.objects.create(
        name="Granola"
    )
    Type.objects.create(
        name="Gym Bro"
    )
    Type.objects.create(
        name="Cowboy"
    )
    Type.objects.create(
        name="Star Wars"
    )
    Type.objects.create(
        name="Clown"
    )
    Type.objects.create(
        name="Drag"
    )
    Type.objects.create(
        name="Elderly"
    )
    Type.objects.create(
        name="Corporate"
    )
    Type.objects.create(
        name="Dirty"
    )

if __name__ == "__main__":
    initial_data()