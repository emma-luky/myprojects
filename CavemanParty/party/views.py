from django.shortcuts import render, redirect
from . import models
from django.http import JsonResponse
import random
from django.views.decorators.csrf import csrf_protect
# Create your views here.
def get_type():
    all_types = models.Type.objects.filter(used=False)
    if all_types.exists():
        random_type = random.choice(all_types)
        random_type.used = True
        random_type.save()
        return random_type
    else:
        return Exception

@csrf_protect
def currentCavemen(request):
    cavemen = models.Caveman.objects.all().order_by("-id")
    if len(cavemen) == 0:
        empty = True
    else:
        empty = False
    return render(request, "currentCavemen.html", dict(cavemen=cavemen,
                                                       empty=empty))
@csrf_protect
def cavemanGenerator(request):
    valid_name = False
    response = ""
    if request.method == "POST":
        name = request.POST.get('name', '')
        if len(name.strip()):
            if models.Caveman.objects.filter(name=name).exists():
                response = f"{name} already is a caveman"
            else:
                try:
                    chosen_type=get_type()
                    current_caveman = models.Caveman(name=name, type=chosen_type)
                    current_caveman.save()
                    response = chosen_type.name
                    valid_name = True
                except Exception:
                    response = "No more types exist, please contact emma or isabel"
        else:
            response = "You need to enter your name"
    print("Form submitted successfully")
    return render(request, "cavemanGenerator.html", dict(valid_name=valid_name,
                                                         response=response))

def resources(request):
    return render(request, "resources.html")