from django.db import models


class Car(models.Model):
    SERVICE_CHOICES = [('P', 'Platinum'), ('G', 'Gold')]
    car_model = models.CharField(max_length=100)
    car_owner = models.CharField(max_length=100)
    car_notes = models.CharField(max_length=100)
    car_number = models.CharField(max_length=30)
    description = models.TextField()
    service_type = models.CharField(choices=SERVICE_CHOICES, max_length=1, blank=True)
    submission_date = models.DateTimeField()
    year_old = models.IntegerField(null=True)
    servicing = models.ManyToManyField('Service',blank=True)


class Service(models.Model):
    name = models.CharField(max_length=50)

