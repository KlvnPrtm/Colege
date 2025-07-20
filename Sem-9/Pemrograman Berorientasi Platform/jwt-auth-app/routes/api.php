<?php

use Illuminate\Http\Request;
use Illuminate\Support\Facades\Route;
use App\Http\Controllers\AuthController;

Route::group([
    'prefix' => 'auth'
], function ($router) {
    Route::post('/login', [AuthController::class, 'login']);
    Route::post('/register', [AuthController::class, 'register']);
    Route::post('/logout', [AuthController::class, 'logout']);
    Route::post('/refresh', [AuthController::class, 'refresh']);
    Route::get('/user-profile', [AuthController::class, 'userProfile']);
});

Route::middleware('auth:api')->group(function () {
    Route::get('/user-dashboard', function () {
        return response()->json(['message' => 'Welcome to User Dashboard']);
    });

    Route::group(['middleware' => 'admin'], function () {
        Route::get('/admin-dashboard', [AuthController::class, 'adminDashboard']);
    });
});
